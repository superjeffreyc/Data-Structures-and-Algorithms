import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class ArrayStackTester {

	@Test(expected = Exception.class)
	public void testOverflow() throws Exception {
		System.out.println("----------------------Testing overflow");
		ArrayStack stack = new ArrayStack(10);

		for (int i = 0; i < 10; i++) {
			stack.push(new Integer(i));
		}

	}

	@Test
	public void testPush() throws Exception {
		System.out.println("----------------------Testing push");

		ArrayStack stack = new ArrayStack(2);

		stack.push(new Integer(100));

		assertEquals(100, stack.peek());
	}

	@Test
	public void testPop() throws Exception {
		System.out.println("----------------------Testing pop");

		ArrayStack stack = new ArrayStack(10);

		for (int i = 100; i < 109; i++) {
			stack.push(new Integer(i));
		}

		assertEquals(108, stack.pop());
		assertEquals(8, stack.stackPointer);
	}

	@Test
	public void testPeek() throws Exception {
		System.out.println("----------------------Testing peek");

		ArrayStack stack = new ArrayStack(10);

		for (int i = 0; i < 9; i++) {
			stack.push(new Integer(i));
		}

		assertEquals(8, stack.peek());
	}
}
