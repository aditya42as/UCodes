class Program2 {
	public static void main(String arg[]) {

		int ch = Integer.parseInt(arg[3]);
		int p = Integer.parseInt(arg[0]);
		int r = Integer.parseInt(arg[1]);
		int n = Integer.parseInt(arg[2]);
		int amount;

		switch(ch) {

			case 1:

				amount = p * (1 + r/ 100) * n;
				System.out.print("Term Deposit: ");
				System.out.println(amount);
				break;

			case 2:

				amount = p * n + p * n * (n+1) / 2 * r / 100 * 1 / 12;
				System.out.print("Recurring Deposit: ");
				System.out.println(amount);	
				break;

			default: 

				System.out.println("Invalid Input");
				
		}
	}
}