#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    puts("usage : add-nbo <file1> <file2>");
    exit(1);
  }

  FILE* f1 = fopen(argv[1],"r");
  FILE* f2 = fopen(argv[2],"r");

  if(f1 == NULL || f2 == NULL)
  {
    puts("file open error");
    exit(1);
  }

  uint32_t num1, num2, ans;
  fread(&num1,4,1,f1);
  fread(&num2,4,1,f2);

  num1 = ntohl(num1);
  num2 = ntohl(num2);
  ans = num1 + num2;

  printf("%u(%#x) + %u(%#x) = %u(%#x)\n",num1,num1,num2,num2,ans,ans);

  fclose(f1);
  fclose(f2);
  return 0;
}
