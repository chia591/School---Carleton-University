package comp2402a1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.ArrayList;

public class Part7 {
	
	/**
	 * Your code goes here - see Part0 for an example
	 * @param r the reader to read from
	 * @param w the writer to write to
	 * @throws IOException
	 */
	public static void doIt(BufferedReader r, PrintWriter w) throws IOException {
		// Your code goes here - s
		ArrayList a = new ArrayList();
		ArrayList f = new ArrayList();
		ArrayList b = new ArrayList();
		String line;

		for (int i = 0; i < 2000; i++){
			line = r.readLine();
			if(line == null){
				break;
			}
			a.add(line);
		}
		Collections.sort(a);

		if(a.size() == 2000){
			for(int i = 0; i < 1000; i++){
				f.add(a.get(i));
			}
			for(int i = 1000; i < 2000; i++){
				b.add(a.get(i));
			}
		}

		for (line = r.readLine(); line != null; line = r.readLine()) {
				if(line.compareTo(f.get(999).toString()) == 0 || line.compareTo(b.get(0).toString()) == 0){
					continue;
				}
				else if(line.compareTo(f.get(999).toString()) < 0){
					f.add(line);
					Collections.sort(f);
					f.remove(1000);
				}
				else if(line.compareTo(b.get(0).toString()) > 0){
					b.add(line);
					Collections.sort(b);
					b.remove(0);
				}
				else{
					w.println(line);
				}
		}
	}

	/**
	 * The driver.  Open a BufferedReader and a PrintWriter, either from System.in
	 * and System.out or from filenames specified on the command line, then call doIt.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader r;
			PrintWriter w;
			if (args.length == 0) {
				r = new BufferedReader(new InputStreamReader(System.in));
				w = new PrintWriter(System.out);
			} else if (args.length == 1) {
				r = new BufferedReader(new FileReader(args[0]));
				w = new PrintWriter(System.out);				
			} else {
				r = new BufferedReader(new FileReader(args[0]));
				w = new PrintWriter(new FileWriter(args[1]));
			}
			long start = System.nanoTime();
			doIt(r, w);
			w.flush();
			long stop = System.nanoTime();
			System.out.println("Execution time: " + 10e-9 * (stop-start));
		} catch (IOException e) {
			System.err.println(e);
			System.exit(-1);
		}
	}
}
