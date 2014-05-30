import java.util.Arrays;

public class TwoSides {

  private final int pointNum;
  private final int trackNum;
  private final int mod;

  int[][] f; // num between two plan
  int[][] g; // no line num between two plan

  public TwoSides(int pointNum, int trackNum) {
    this.pointNum = pointNum;
    this.trackNum = trackNum;
    mod = (pointNum + 1) * trackNum + 1;
  }

  private int noLine(int a, int b) {
    if (g[a][b] != -1) {
      return g[a][b];
    }
    Plan pa = new Plan(a);
    Plan pb = new Plan(b);
    if (isPlanCross(pa, pb)) {
      return g[a][b] = 0;
    }
    if (pa.lower < pa.upper) {
      pa.upsideDown();
      pb.upsideDown();
      int na = pa.getId();
      int nb = pb.getId();
      return g[a][b] = noLine(na, nb);
    }
    g[a][b] = 0;

    Plan pc = new Plan();
    pc.lower = pa.lower;
    for (int r = pa.upper + 2; r < pb.upper; r++) {
      pc.upper = r;
      for (int t = 0; t < trackNum && t != pa.track && t != pb.track; t++) {
        pc.track = t;
        int nc = pc.getId();
        int temp = noLine(nc, b) + 1;
        if (pa.isStraight() && t == trackNum - 1) {
          temp *= 2;
        }
        g[a][b] += temp;
      }
    }
    if (pa.isStraight()) {
      if (pa.upper + 1 < pb.upper) {
        Plan npa = new Plan();
        npa.lower = npa.upper = pa.upper + 1;
        npa.track = -1;
        int na = npa.getId();
        g[a][b] += noLine(na, b);
        npa.lower = pa.lower;
        npa.track = 0;
        na = npa.getId();
        g[a][b] += noLine(na, b);
      }
    } else {
      Plan npa = new Plan();
      npa.upper = pa.upper + 1;
      npa.lower = pa.lower;
      npa.track = pa.track;
      int na = npa.getId();
      g[a][b] += noLine(na, b);
    }
    // System.out.printf("noLine %d %d %d\n", a, b, g[a][b]);
    return g[a][b];
  }

  private int insertLine(int a, int b) {

    if (f[a][b] != -1) {
      return f[a][b];
    }
    f[a][b] = 0;
    Plan pa = new Plan(a);
    Plan pb = new Plan(b);
    for (int c = a; c < b; c++) {
      Plan pc = new Plan(c);
      if (isPlanCross(pa, pc) || isPlanCross(pb, pc)) {
        continue;
      }
      f[a][b] += (noLine(a, c) + 1) * insertLine(c, b);
    }
    f[a][b] += noLine(a, b) + 1;
    System.out.printf("insertLine %d %d %d\n", a, b, f[a][b]);
    return f[a][b];
  }

  public int getPlanNum() {
    int a = 0;
    int b = mod * (pointNum + 1);
    int size = mod * (pointNum + 2);
    f = new int[size][size];
    g = new int[size][size];
    for (int i = 0; i < size; i++) {
      Arrays.fill(f[i], -1);
      Arrays.fill(g[i], -1);
    }
    return insertLine(a, b);
  }

  public static boolean isPlanCross(Plan a, Plan b) {
    if (a.upper == b.upper) {
      return true;
    }
    if (a.upper > b.upper) {
      Plan c = a;
      a = b;
      b = c;
    }
    if (b.lower <= a.lower) {
      return true;
    }
    if (a.isStraight() || b.isStraight()) {
      return false;
    }
    return a.lower >= b.upper && a.track <= b.track;
  }

  class Plan {

    public int upper;
    public int lower;
    public int track;

    public Plan() {}

    public Plan(int id) {

      upper = id / mod;
      id = id % mod;
      if (id == 0) {
        lower = upper;
        track = -1;
      } else {
        id--;
        track = id % trackNum;
        lower = id / trackNum;
        if (lower >= upper) {
          lower++;
        }
      }
    }

    public boolean isStraight() {
      return upper == lower;
    }

    public void upsideDown() {
      int t = upper;
      upper = lower;
      lower = t;
      if (track != -1) {
        track = trackNum - 1 - track;
      }
    }

    public int getId() {
      if (isStraight()) {
        return upper * mod;
      }
      int t = lower < upper ? lower : lower - 1;
      return upper * mod + t * trackNum + track + 1;
    }
  }

  public static void main(String[] args) {
    TwoSides ts = new TwoSides(9, 4);
    int ans = ts.getPlanNum();
    System.out.println(ans);
  }

}
