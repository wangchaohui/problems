import org.junit.Assert;
import org.junit.Test;


public class TwoSidesTest {

  @Test
  public void test() {
    TwoSides ts = new TwoSides(9, 4);
    TwoSides.Plan a = ts.new Plan(83);
    Assert.assertEquals(2, a.upper);
    Assert.assertEquals(0, a.lower);
    Assert.assertEquals(0, a.track);
  }

  @Test
  public void testUpsideDown() {
    TwoSides ts = new TwoSides(9, 4);
    TwoSides.Plan a = ts.new Plan(83);
    a.upsideDown();
    Assert.assertEquals(0, a.upper);
    Assert.assertEquals(2, a.lower);
    Assert.assertEquals(3, a.track);
  }

  @Test
  public void test0() {
    TwoSides ts = new TwoSides(0, 1);
    Assert.assertEquals(1, ts.getPlanNum());
  }

  @Test
  public void test1() {
    TwoSides ts = new TwoSides(1, 1);
    Assert.assertEquals(2, ts.getPlanNum());
  }

  @Test
  public void test20() {
    TwoSides ts = new TwoSides(2, 0);
    Assert.assertEquals(4, ts.getPlanNum());
  }

  @Test
  public void test21() {
    TwoSides ts = new TwoSides(2, 1);
    Assert.assertEquals(8, ts.getPlanNum());
  }

  @Test
  public void test22() {
    TwoSides ts = new TwoSides(2, 2);
    Assert.assertEquals(13, ts.getPlanNum());
  }
}
