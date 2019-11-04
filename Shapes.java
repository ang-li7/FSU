import java.util.Scanner;

public class Shapes {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int next = num*2 -1;
		String [][]a = new String[num][next];
		for(int i =0; i<num; i++) {
			for(int j = 0; j<next; j++) {
				a[i][j] = " ";
			}
		}
		for(int i =0; i<num; i++) {
			if (i == 0 || i== num-1){
				for(int j = 0; j<next; j++) {
					if(j%2 == 0) {
						a[i][j] = "*";
					}
				}
			}
			
		}
		for(int i =0; i<num; i++) {
			for(int j = 0; j<next; j++) {
					if(j == 0|| j==next-1) {
						a[i][j] = "*";
					}
			}
		}
		a[num/2][next/2] = "x";
		String[] x = (num+"").split("");
		String[] y = (next+"").split("");


		int count = 0;
		for(int i = x.length; i>0; i--) {
			a[num/2][next/2-i] = x[count];
			count = count + 1;
		}
		count = 0;
		for(int i= 0; i<y.length; i++) {
			a[num/2][next/2+1+i] = y[i];
			count = count + 1;
		}
		for(int i =0; i<num; i++) {
			for(int j = 0; j<next; j++) {
				System.out.print(a[i][j]);
			}
			System.out.println();
		}
	}
}
