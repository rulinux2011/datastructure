#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//学生节点

typedef struct _STU{
       char arrStuNum[10];
       char arrStuName[10];
       int iStuScore;
       struct _STU* pNext;
}STUNODE;

//声明链表头和尾
STUNODE *g_pHead=NULL;
STUNODE *g_pEnd=NULL;

//添加一个学生的信息，函数声明
void AddStuMSG(char* arrStuNum, char* arrStuName, int iStuScore);

//释放链表的函数声明
void FreeLinkData();

//打印链表
void ShowData();

//字符串转INT
int convert_to_int(int n,char *array)
{
            int res=0,l=1;
            for(int i=n-1;i>=0;--i)
            {
                        if(array[i]!=',')
                        {
                                   res+= (array[i]-'0')*l;
                                   l*=10;
                        }
            }
            return res;

}

//在链表尾添加学生信息
void AddStuMSG(char* arrStuNum, char* arrStuName, int iStuScore){
            //创建一个节点
            STUNODE * pTemp=malloc(sizeof(STUNODE));
            //检验参数的合法性
            if(arrStuNum==NULL||arrStuName==NULL||iStuScore<0){
                        printf("Input Error!\n");
            }
            //节点成员赋初值
            strcpy(pTemp->arrStuNum,arrStuNum);
            strcpy(pTemp->arrStuName,arrStuName);
            pTemp->iStuScore=iStuScore;
            pTemp->pNext=NULL;
            //插入链表
            if(g_pHead==NULL||g_pEnd==NULL){     //链表是空的时候
                        g_pHead=pTemp;
            }else{  //链表不为空的时候
                        g_pEnd->pNext=pTemp;
            }
            g_pEnd=pTemp;
}

//在链表头增加一个节点
void AddStuMSGToLinkHead(char* arrStuNum, char* arrStuName, int iStuScore){
                 //创建一个节点
            STUNODE * pTemp=malloc(sizeof(STUNODE));
            //检验参数的合法性
            if(arrStuNum==NULL||arrStuName==NULL||iStuScore<0){
                        printf("Input Error!\n");
            }
            //节点成员赋初值
            strcpy(pTemp->arrStuNum,arrStuNum);
            strcpy(pTemp->arrStuName,arrStuName);
            pTemp->iStuScore=iStuScore;
            pTemp->pNext=NULL;
            //如果链表为空
            if(g_pHead==NULL||g_pEnd==NULL)
            {
                 g_pHead=pTemp;
                 g_pEnd=pTemp;
            }else{
                   pTemp->pNext=g_pHead;
                   g_pHead=pTemp;
            }

}

//在指定位置后面添加节点
void InsertNode(STUNODE *pTemp,char* arrStuNum, char* arrStuName, int iStuScore)
{
            //创建节点
            STUNODE* pNewTemp=malloc(sizeof(STUNODE));
            //成员赋值
            strcpy(pNewTemp->arrStuNum,arrStuNum);
            strcpy(pNewTemp->arrStuName,arrStuName);
            pNewTemp->iStuScore=iStuScore;
            pNewTemp->pNext=NULL;
            //插入
           if(pTemp==g_pEnd)   //如果是尾节点
          {
                 g_pEnd->pNext=pNewTemp;
                 g_pEnd=pNewTemp;
          }
          else
          {
                pNewTemp->pNext=pTemp->pNext;
                pTemp->pNext=pNewTemp;
          }
}


//查找指定的链表元素,查找指定学生
STUNODE * FindStuByNum(char * arrStuNum)
{
            STUNODE*pTemp=g_pHead;
            //检测参数合法性
            if(arrStuNum==NULL)
            {
                        printf("Wrong Input!\n");
                        return NULL;
            }

            //遍历链表,判断是否为空
            if(NULL==g_pHead||NULL==g_pEnd)
            {
                        printf("It's empty!\n");
                        return NULL;
            }
            //遍历链表
            while(pTemp!=NULL){
                        if(strcmp(pTemp->arrStuNum,arrStuNum)==0)
                        {
                                   return pTemp;
                        }
                        pTemp=pTemp->pNext;
            }
            printf("Did not find the node!\n");
            return NULL;
}

//删除指定节点
void DeleteStuNode(STUNODE* pNode)
{
         //只有一个节点时
         if(g_pEnd==g_pHead)
         {
                     free(g_pHead);
                     g_pHead=NULL;
                     g_pEnd=NULL;
         }
         //两个节点
         else if(g_pHead->pNext==g_pEnd)
         {
                     //如果是删除头
                    if(g_pHead==pNode)
                    {
                                free(g_pHead);
                                g_pHead=g_pEnd;
                    }
                    //如果是删除尾
                    else
                    {
                                free(g_pEnd);
                                g_pEnd=g_pHead;
                                g_pHead->pNext=NULL;
                    }
         }
         //节点数大于等于三
         else
         {
                     STUNODE* pTemp=g_pHead;
                     //判断头节点
                     if(g_pHead==pNode)
                     {
                                 free(pTemp);
                                 g_pHead=g_pHead->pNext;
                                 pTemp=NULL;
                                 return;
                     }
                     while(pTemp)
                     {
                                 if(pTemp->pNext==pNode)
                                 {
                                      if(pNode==g_pEnd)
                                      {
                                                  free(pNode);
                                                  pNode=NULL;
                                                  g_pEnd=pTemp;
                                                  g_pEnd->pNext=NULL;
                                                  return;
                                      }
                                      else
                                      {
                                                  STUNODE* p=pTemp->pNext;
                                                  pTemp->pNext=pNode->pNext;
                                                  free(p);
                                                  p=NULL;
                                                  return;
                                      }

                                 }
                                 pTemp=pTemp->pNext;
                     }
         }
}



//清空链表
void FreeLinkData(){
            STUNODE* pTemp=g_pHead;//定义一个指针指向链表头
            while(g_pHead!=NULL){
                        pTemp=g_pHead;
                        g_pHead=g_pHead->pNext;
                        free(pTemp);
            }
}

//打印链表
void ShowData(){
            STUNODE* pTemp=g_pHead;
            while(pTemp!=NULL){
                        printf("NUM:%s,NAME:%s,SCORE:%d\n",pTemp->arrStuNum,pTemp->arrStuName,pTemp->iStuScore);
                        pTemp=pTemp->pNext;
            }

}

//保存信息
void SaveStuToFile()
{
            FILE *pFile=NULL;
            STUNODE* pTemp=g_pHead;
            char strBuf[30]={0};
            char strScore[10]={0};
            //判断链表是否为空
            if(g_pHead==NULL)
            {
                        printf("No Student's info!\n");
                        return;
            }
            //打开文件
            pFile=fopen("dat.dat","wb+");
            if(NULL==pFile)
            {
                        printf("Open File Failed!\n");
            }
            //操作文件指针
            while(pTemp)
            {
                        //学号赋值
                        strcpy(strBuf,pTemp->arrStuNum);
                        strcat(strBuf,".");
                        //姓名赋值
                        strcat(strBuf,pTemp->arrStuName);
                        strcat(strBuf,".");
                        //分数赋值
                        //itoa(pTemp->iStuScore,strScore,10);
                        sprintf(strScore,"%d",pTemp->iStuScore);
                        strcat(strBuf,strScore);
                        fwrite(strBuf,1,strlen(strBuf),pFile);
                        fwrite("\r\n",1,strlen("\r\n"),pFile);
                        pTemp=pTemp->pNext;
            }

            //关闭文件
            fclose(pFile);
}

//从文件中读取信息
void ReadStuFromFile()
{
            FILE* pFile=fopen("dat.dat","rb+");
            char strBuf[30]={0};
            char strStuNum[10]={0};
            char strStuName[10]={0};
            char strStuScore[10]={0};

            if(NULL==pFile)
            {
                        printf("Open File Failed!\n");
                        return;
            }
            //操作指针，读取函数
           while(NULL!=fgets(strBuf,30,pFile))
           {
                    int i=0;
                    int count=0;
                    int j=0;
                    for(i=0;strBuf[i]!='\r';++i)
                    {
                            if(count==0)
                            {
                                    strStuNum[i]=strBuf[i];
                                    if('.'==strBuf[i])
                                    {
                                                strStuNum[i]='\0';
                                                count++;
                                    }
                            }
                            else if(count==1) //第一个'.'
                            {
                                    strStuName[j]=strBuf[i];
                                    j++;
                                    if('.'==strBuf[i])
                                    {
                                                strStuName[j-1]='\0';
                                                count++;
                                                j=0;
                                    }
                            }
                            else  //第二个'.'
                            {
                                     strStuScore[j]=strBuf[i];
                                     j++;
                            }

                    }
               //插入到链表
            AddStuMSG(strStuNum, strStuName, convert_to_int(strlen(strStuScore),strStuScore));
           // AddStuMSG(strStuNum, strStuName,atoi(strStuScore));
           }
            fclose(pFile);
}




//显示指令
void ShowOrder(){
            printf("*********************StudentInfoManagementSys***************************\n");
            printf("*********************FlowThisInstructions*******************************\n");
            printf("***           1.Insert one stdudent's info(At End)                   ***\n");
            printf("***           11.Insert one stdudent's info(At Head)                 ***\n");
            printf("***           111.Insert one stdudent's info(At any element)         ***\n");
            printf("***           2.Search one stdudent's info(Num/Name)                 ***\n");
            printf("***           3.Alter one stdudent's info                            ***\n");
            printf("***           4.Save the info to files                               ***\n");
            printf("***           5.Read the info from files                             ***\n");
            printf("***           6.Delete one stdudent's info                           ***\n");
            printf("***           7.Undo the deleteing                                   ***\n");
            printf("***           8.Show all  info                                       ***\n");
            printf("***           0.Quit                                                 ***\n");
            printf("************************************************************************\n");
}

int main(){
            int nOrder=-1;
            char arrStuNum[10]={'\0'};
            char arrStuName[10]={'\0'};
            int iStuScore=-1;
            int nflag=1;
            STUNODE* pTemp=NULL;

            ShowOrder();


            while(nflag)
            {
            printf("Please take your order(10.Details of the orders):");
            scanf("%d",&nOrder);

            	switch(nOrder){
		case 1:
		      //TODO:添加一个学生的信息
		     printf("Student's Num:\n");
		     scanf("%s",arrStuNum);
		     printf("Student's Name:\n");
		     scanf("%s",arrStuName);
		     printf("Student's Score:\n");
		     scanf("%d",&iStuScore);
		     AddStuMSG(arrStuNum,arrStuName,iStuScore);
                             break;
                        case 11:
                             printf("Student's Num:\n");
		     scanf("%s",arrStuNum);
		     printf("Student's Name:\n");
		     scanf("%s",arrStuName);
		     printf("Student's Score:\n");
		     scanf("%d",&iStuScore);
		     AddStuMSGToLinkHead(arrStuNum,arrStuName,iStuScore);
                             break;
                        case 111:
                             printf("Specify Student's Num:\n");
		     scanf("%s",arrStuNum);
		     pTemp=FindStuByNum(arrStuNum);
                             if(NULL!=pTemp)
                             {
                                  printf("Student's Num:\n");
		          scanf("%s",arrStuNum);
		          printf("Student's Name:\n");
		          scanf("%s",arrStuName);
		          printf("Student's Score:\n");
		          scanf("%d",&iStuScore);
		          InsertNode(pTemp,arrStuNum,arrStuName,iStuScore);
                             }

                             break;
                        case 2:
                              printf("Specify Student's Num:\n");
		      scanf("%s",arrStuNum);
		      pTemp=FindStuByNum(arrStuNum);
		      if(NULL!=pTemp)
                              {
                                           printf("NUM:%s,NAME:%s,SCORE:%d\n",pTemp->arrStuNum,pTemp->arrStuName,pTemp->iStuScore);
                              }
                            break;
                        case 3:
                              printf("Specify Student's Num To Alter:\n");
		      scanf("%s",arrStuNum);
		      pTemp=FindStuByNum(arrStuNum);
		      if(NULL!=pTemp)
                              {
                                          //修改学号
                                          printf("Alter Student's Num To:\n");
                                          scanf("%s",arrStuNum);
                                          strcpy(pTemp->arrStuNum,arrStuNum);
                                          //修改名字
                                          printf("Alter Student's Name To:\n");
                                          scanf("%s",arrStuName);
                                          strcpy(pTemp->arrStuName,arrStuName);
                                          //修改分数
                                          printf("Alter Student's Score To:\n");
                                          scanf("%d",&iStuScore);
                                          pTemp->iStuScore=iStuScore;
                              }
                            break;
                        case 4:
                             //保存学生信息
                            SaveStuToFile();
                            break;
                        case 5:
                            //读取学生信息
                            ReadStuFromFile();
                            break;
                        case 6:
                              printf("Specify Student's Num To Delete:\n");
		      scanf("%s",arrStuNum);
		      pTemp=FindStuByNum(arrStuNum);
		      if(NULL!=pTemp)
                              {
                                      DeleteStuNode(pTemp);
                              }
                            break;
                        case 7:
                            //释放链表
                            FreeLinkData();
                            g_pHead=NULL;
                            g_pEnd=NULL;
                            //恢复
                            ReadStuFromFile();


                            break;
                        case 8:
                             ShowData();
                             break;
                        case 10:
                        //查看指令
                             ShowOrder();
                             break;
                        case 0:
                        //退出
                             nflag=0;
                             break;
		default:
		      printf("Wrong Orders!\n");
            }


	}

	SaveStuToFile();

	//释放链表
	FreeLinkData();
            return 0;
}

