#include "LoserTree.h"
#include "math.h"
#include "IOSTREAM"
LoserTree::LoserTree(int nway,int *inputArray )
{
     k = nway;
     iArray = inputArray;
     matchnodes = new int[(k-1) * 3];
     for(int i=0;i<(k-1)*3;i++)
     {

         matchnodes[i]=10000;
     }
}

LoserTree::~LoserTree()
{
    //dtor
}
void LoserTree::initialize()
{

 int i=0;
 int nodeindex;
 while(i<k)
 {
     nodeindex = (((k+i)/2)-1);
     if(k%2!=0) nodeindex = (k+i)/2;
     if(i==k-1)
     {
       replace(iArray[i],0);
       return;
     }

     matchnodes[nodeindex*3] = iArray[i];
     matchnodes[nodeindex *3+ 2]= iArray[i+1];
     if(iArray[i]>iArray[i+1])
     {

          matchnodes[nodeindex*3 + 1] = iArray[i];
          replace(iArray[i+1],nodeindex);

     }
     else
     {

         matchnodes[nodeindex*3 + 1] = iArray[i+1];
         replace(iArray[i],nodeindex);
     }

 i = i+2;

 }

}

void LoserTree::replace(int element,int nodeindex)
{

  if(nodeindex == 0)
  {

      if(element>matchnodes[nodeindex+1])
      {
        std::cout << matchnodes[nodeindex+1];
        matchnodes[nodeindex+1] = element;
        return;

      }
      std::cout<<element;
      return;
  }
  if(nodeindex%2==0)
  {
      nodeindex = nodeindex - 1;
  }
  if(matchnodes[(nodeindex/2)*3 + 1]==10000)
  {

      matchnodes[(nodeindex/2)*3+1] = element;
      return;
  }
  if(matchnodes[(nodeindex/2)*3+1]>element)
    replace(element,nodeindex/2);
  else
  {
      int matchnodeelement = matchnodes[(nodeindex/2)*3+1];
      matchnodes[(nodeindex/2)*3+1] = element;
      replace(matchnodeelement,nodeindex/2);
  }
}






