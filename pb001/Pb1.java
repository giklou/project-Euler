public class Pb1
{
	public static int sumArith(int n, int max)
	{
		int ind = (max - 1)/n;
		return n*ind*(ind+1)/2;
	}

	public static void main(String[] args)
	{
		int sum = sumArith(3, 1000) + sumArith(5, 1000) - sumArith(15, 1000);
		System.out.println("Sum = " + sum);
	}
}
