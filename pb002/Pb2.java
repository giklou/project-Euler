public class Pb2
{
	public static void main(String[] args)
	{
		int sum = 2;
		int fibEven = 8;
		int fibEven1 = 2;
		int fibEven2 = 0;

		while(fibEven<4000000)
		{
			sum += fibEven;
		
			fibEven2 = fibEven1;
			fibEven1 = fibEven;
			fibEven = 4*fibEven + fibEven2;
		}

		System.out.println("Sum = " + sum);
	}
}
