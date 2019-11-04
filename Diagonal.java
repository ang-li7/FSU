import java.util.Scanner;

public class Diagonal {
	public static void main(String []args) {
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		int[][] a = new int[size][size];
		for(int i = 0; i<size; i++) {
			for(int j = 0; j<size; j++) {
				a[i][j] = sc.nextInt();
			}
		}

		
		int [] nums = new int[10];
		for(int i = 0; i<size; i++) {
			for(int j = 0; j<size; j++) {
				if(i == j || i==size-j-1) {
					int x = a[i][j];
					nums[x] = nums[x] + 1;
				}
			}
		}
		for(int i = 0; i<nums.length; i++) {
			System.out.println(i + ": "+ nums[i]);
		}
	}

}
