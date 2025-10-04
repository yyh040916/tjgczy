#include<stdio.h>
int main()
{
    char ch;
    int pos,ans;
    while((ch=getchar())!='#')
    {
        pos=1;
        ans=0;
        ans+=pos*(ch - 'A' + 1);
        pos++;
        while((ch=getchar())!='\n') 
        {
            if(ch ==' ') 
                ans+=pos*0;
            else
                ans+= pos*(ch - 'A' + 1);
            pos++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
