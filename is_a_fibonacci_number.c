bool isPerfectSquare(int x)
{
    int s = (int) sqrt(x);
    return (s*s == x);
}
  
// Returns true if n is a Fibonacci Number, else false
bool isFibonacci(int x)
{
    return isPerfectSquare(5*x*x + 4) ||
           isPerfectSquare(5*x*x - 4);
}
