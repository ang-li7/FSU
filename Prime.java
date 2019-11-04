import java.util.ArrayList;
import java.util.Scanner;

public class Prime {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		ArrayList<Integer> a = new ArrayList<Integer>();
		for(int i = 2; i<=n; i++) {
			if(isPrime(i)) {
				a.add(i);
			}
		}
		for(int i = 0; i<m; i++) {
			int x = sc.nextInt();
			if (a.size()>0 && x%2 == 0) {
				a.remove(a.size()-1);
			}
			else {
				a.add(x);
			}
		}
		for(int i = 0; i<a.size()-1; i++) {
			System.out.print(a.get(i)+ " ");
		}
		System.out.println(a.get(a.size()-1));
		
	}
	
	public static boolean isPrime(int n) {
		for(int i = 2; i<n; i++) {
			if(n%i == 0) {
				return false;
			}
		}
		return true;
	}
}

