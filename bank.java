import java.util.*;

public class bank {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String[] grant = sc.nextLine().split(" ");
		int tcount = Integer.parseInt(grant[0]);
		boolean person = false;
		ArrayList <String> line = new ArrayList<String>();
		String[] a = new String[tcount];
		String priority = "";
		int counter = 0;
		int pointer = 1;
		String name = "";
		while(!grant[pointer].equals("STOP")) {
			System.out.println("STOP INF");
			name = grant[pointer];
			if(name.contains("0")||name.contains("1")||name.contains("2")||name.contains("3")||name.contains("4")||name.contains("5")||name.contains("6")||name.contains("7")||name.contains("8")||name.contains("9")) {
				person = false;
			}
			else {
				person = true;
			}
			int p;
			if(person) {
				priority = grant[pointer+1];
				pointer = pointer + 1;
				counter = 0;
				p = Integer.parseInt(priority);
				if (line.size() == 0)
				{
					line.add(name);
					line.add(priority);
				}
				else {
					System.out.println("hiii");
					System.out.println(p);
					
					for(int i = 0; i<line.size(); i+=2) {
						if(p> Integer.parseInt(line.get(i+1))) 
						{
							counter +=2;
						}
						
					}
					line.add(counter, name);
					line.add(counter + 1, name);
					System.out.println("byeee");
				}
				

			}
			else {
				a[Integer.parseInt(name) - 1] = line.get(0);
				line.remove(0);
				line.remove(0);
			}
			
			
			
			pointer = pointer + 1;
		}
		

		for (int j = 0; j < line.size(); j+=2)
		{
			System.out.println(line.get(j));
		}
}
}
