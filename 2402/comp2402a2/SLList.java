package comp2402a2;

import java.util.AbstractList;
import java.util.Iterator;
import java.util.Queue;
import java.util.NoSuchElementException;

/**
 * An implementation of a FIFO Queue as a singly-linked list.
 * This also includes the stack operations push and pop, which
 * operate on the head of the queue
 * @author morin
 *
 * @param <T> the class of objects stored in the queue
 */
public class SLList<T> extends AbstractList<T> implements Queue<T> {
	class Node {
		T x;
		Node next;
	}

	/**
	 * Front of the queue
	 */
	Node head;

	/**
	 * Tail of the queue
	 */
	Node tail;

	/**
	 * The number of elements in the queue
	 */
	int n;

	public T get(int i) {
		// TODO: Implement this
		if(this.head == null){ return null; }
		Node a = this.head;
		int l = 0;
		while(l < i){
			a = a.next;
			l++;
		}
		if (i < 0 || i > n - 1) throw new IndexOutOfBoundsException();
		return a.x;
	}

	public T set(int i, T x) {
		// TODO: Implement this
		if(this.head == null){ return null; }
		Node a = this.head;
		Node c = new Node();
		int l = 0;
		while(l < i){
			a = a.next;
			l++;
		}
		c.x = a.x;
		a.x = x;
		if (i < 0 || i > n - 1) throw new IndexOutOfBoundsException();
		return c.x;
	}

	public void add(int i, T x) {
		// TODO: Implement this
		Node nNde = new Node();
		nNde.x = x;
		nNde.next = null;
		if(this.head == null){ 
			if(i != 0){ return; }
			else{
				this.head = nNde;
				this.tail = nNde;
				this.n++;
				return;
			}
		}
		if(i == 0){
			nNde.next = this.head;
			this.head = nNde;
			this.n++;
			return;
		}
		Node a = this.head;
		Node c = null;
		int l = 0;
		while (l < i) {
			c = a;
			a = a.next;
			l++;
		}
		if(l == n-1){
			a.next = nNde;
			this.tail = nNde;
			this.n++;
			return;
		}
		nNde.next = a;
		c.next = nNde;
		this.n++;
		if (i < 0 || i > n-1) throw new IndexOutOfBoundsException();
	}

	public T remove(int i) {
		// TODO: Implement this
		if(this.head == null){ return null; }
		Node a = this.head;
		if(i == 0){
			this.head = a.next;
			this.n--;
			return a.x;
		}
		Node c = null;
		int l = 0;
		while(l < i) {
			c = a;
			a = a.next;
			l++;
		}
		if(l == n-1){
			c.next = null;
			this.tail = c;
			this.n--;
			return a.x;
		}
		c.next = a.next;
		a.next = null;
		this.n--;
		if (i < 0 || i > n-1) throw new IndexOutOfBoundsException();
		return a.x;
	}

	public void reverse() {
		// TODO: Implement this

		if(this.head == null || this.head.next == null) { return; }
		Node d = null;
		Node a = this.head;
		this.tail = this.head;
		while (a != null) {
			Node next = a.next;
			a.next = d;
			d = a;
			a = next;
		}
		this.head = d;
	}

	public Iterator<T> iterator() {
		class SLIterator implements Iterator<T> {
			protected Node p;

			public SLIterator() {
				p = head;
			}
			public boolean hasNext() {
				return p != null;
			}
			public T next() {
				T x = p.x;
				p = p.next;
				return x;
			}
			public void remove() {
				throw new UnsupportedOperationException();
			}
		}
		return new SLIterator();
	}

	public int size() {
		return n;
	}

	public boolean add(T x) {
		Node u = new Node();
		u.x = x;
		if (n == 0) {
			head = u;
		} else {
			tail.next = u;
		}
		tail = u;
		n++;
		return true;
	}

	public boolean offer(T x) {
		return add(x);
	}

	public T peek() {
		if (n == 0) return null;
		return head.x;
	}

	public T element() {
		if (n == 0) throw new NoSuchElementException();
		return head.x;
	}

	public T poll() {
		if (n == 0)
			return null;
		T x = head.x;
		head = head.next;
		if (--n == 0)
			tail = null;
		return x;
	}

	/**
	 * Stack push operation - push x onto the head of the list
	 * @param x the element to push onto the stack
	 * @return x
	 */
	public T push(T x) {
		Node u = new Node();
		u.x = x;
		u.next = head;
		head = u;
		if (n == 0)
			tail = u;
		n++;
		return x;
	}

	protected void deleteNext(Node u) {
		if (u.next == tail)
			tail = u;
		u.next = u.next.next;
	}

	protected void addAfter(Node u, Node v) {
		v.next = u.next;
		u.next = v;
		if (u == tail)
			tail = v;
	}

	protected Node getNode(int i) {
		Node u = head;
		for (int j = 0; j < i; j++)
			u = u.next;
		return u;
	}

	/**
	 * Stack pop operation - pop off the head of the list
	 * @return the element popped off
	 */
	public T remove() {
		if (n == 0)	return null;
		T x = head.x;
		head = head.next;
		if (--n == 0) tail = null;
		return x;
	}

	public T pop() {
		if (n == 0)	return null;
		T x = head.x;
		head = head.next;
		if (--n == 0) tail = null;
		return x;
	}

	public void printList()
	{
		Node current = this.head;
		while (current != null)
		{
			System.out.print(current.x+"->");
			current = current.next;
		}
	}


	public static void main(String[] args) {

	}

}
