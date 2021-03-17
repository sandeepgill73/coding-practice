//determine an integer is a power of 2?
int BitLogic (unsigned int x)
{
return ((x != 0) && !(x & (x - 1)));
}