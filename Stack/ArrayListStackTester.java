import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class ArrayListStackTester {

	@Test
	public void testPush() {
		System.out.println("----------------------Testing push");

		ArrayListStack stack = new ArrayListStack();

		stack.push(new Integer(100));

		assertEquals(100, stack.peek());
	}

	@Test
	public void testPop() {
		System.out.println("----------------------Testing pop");

		ArrayListStack stack = new ArrayListStack();

		for (int i = 100; i < 109; i++) {
			stack.push(new Integer(i));
		}

		assertEquals(108, stack.pop());
		assertEquals(8, stack.stackPointer);
	}

	@Test
	public void testPeek() {
		System.out.println("----------------------Testing peek");

		ArrayListStack stack = new ArrayListStack();

		for (int i = 0; i < 9; i++) {
			stack.push(new Integer(i));
		}

		assertEquals(8, stack.peek());
	}

	@Test
	public void testLargeStack() throws Exception {
		System.out.println("----------------------Testing peek");

		ArrayListStack stack = new ArrayListStack();

		for (int i = 0; i < 100000; i++) {
			stack.push(new Integer(i));
		}

		assertEquals(99999, stack.peek());
	}
}
