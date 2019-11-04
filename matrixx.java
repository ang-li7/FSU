import java.util.Scanner;

public class matrixx {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		int[][] a = new int[size][size];
		for(int i = 0; i<size; i++) {
			for(int j= 0; j<size; j++) {
				a[i][j] = size - Math.abs(i-j);
			}
		}
		for(int i = 0; i<size; i++) {
			for(int j = 0; j<size; j++) {
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}
	}
}
