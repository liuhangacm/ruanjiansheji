#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
  
#define CHECKBROADSIZE 21 //棋盘的大小

int g_checkboard[CHECKBROADSIZE][CHECKBROADSIZE];  //棋盘对局的数据

int g_currentGamer = 1;//当前下子玩家 黑方 白方

int g_cursorX,g_cursorY;  //当前光标的位置

int g_count=0;  //游戏回合数

//函数

// 进行整个对局，返回赢家信息，函数的声明
int RunGame();

//初始化
void Init();

//绘制棋盘
void DrawCheckboard();

//下子 成功 成功 1 失败 0
int Put();

//判断输赢
int Check();
 
int main()
{
    //设置控制台标题
    SetConsoleTitle("五子棋");
    RunGame();
    return 0;
}

int RunGame()
{
    Init();//初始化
    
    int nInput = 0;//键盘输入值
    
    int Winner = 0; //胜者
    
    while(!Winner)
    {
        //清屏
        system("cls");
         
        //绘制棋盘
        DrawCheckboard();
        
        //获取键盘输入
        nInput = getch();
        
        switch(nInput)
        {
            case ' '://空格
               {
                     //1.下子 => 能不能下子
                     if(Put())
                     {
                         //2.判断输赢
                       Winner = Check();
                         
                         //3.更换玩家
                         g_currentGamer = 3 - g_currentGamer;
                         
                         if(Winner == 1)
                         {
                           printf("白子赢了!\n");
                         }
                         else if(Winner == 2)
                         {
                           printf("黑子赢了!\n");
                         }
                     }
               }
               break;
            case 'a'://向左
               g_cursorY--;
               break;
            case 'd'://向右
               g_cursorY++;
               break;
            case 'w'://向上
               g_cursorX--;
               break;
            case 's'://向下
               g_cursorX++;
               break;
        }
        if(g_cursorY < 0) g_cursorY = CHECKBROADSIZE-1;//左边格子越界转右边
        if(g_cursorY > CHECKBROADSIZE-1) g_cursorY = 0;//右边格子越界转左边
        if(g_cursorX < 0) g_cursorX = CHECKBROADSIZE-1;//上边格子越界转下边
        if(g_cursorX > CHECKBROADSIZE-1) g_cursorX = 0;//下边格子越界转上边
    }
    return 0;
}

//初始化
void Init()
{
    //清空二维数组
    memset(g_checkboard,0,sizeof(g_checkboard));
    
    g_currentGamer = 1;//黑子先下
    
    g_cursorX = CHECKBROADSIZE / 2;
    g_cursorY = CHECKBROADSIZE / 2;
    
    g_count = 0;
}

//绘制棋盘
void DrawCheckboard()
{
    printf("欢迎来到五子棋战场！\n") ;
    for(int i = 0;i < CHECKBROADSIZE;i++)//行
    {
        for(int j = 0;j < CHECKBROADSIZE;j++)//列
        {
            if(i == g_cursorX&& j == g_cursorY)
               printf("☆");
            else if(g_checkboard[i][j] == 1)//下黑子
               printf("●");
            else if(g_checkboard[i][j] == 2)//下白子
               printf("○");
            else if(i == 0 && j == 0)
                   printf("┍");
            else if(i == 0 && j == CHECKBROADSIZE-1)
                   printf("┒");
            else if(i == CHECKBROADSIZE-1 && j == 0)
                   printf("┖");
            else if(i == CHECKBROADSIZE-1 && j == CHECKBROADSIZE-1)
                   printf("┚");
               
            else if(i == 0)
                   printf("┮");
            else if(i ==CHECKBROADSIZE-1)
                   printf("┵");
            else if(j == 0)
                   printf("┞");
            else if(j ==CHECKBROADSIZE-1)
                  printf("┧");
            else
                printf("┽");
            
                
        }
        printf("\n");
    }
}

int Put()
{
   //1.怎样才是下子成功 2.改下哪颗子
   if(g_checkboard[g_cursorX][g_cursorY] == 0)
   {
        g_checkboard[g_cursorX][g_cursorY] = g_currentGamer;
        return 1;
   }
   else
     return 0;
}

int Check()
{
    int  shuiPing = 1; //水平方向
    int  shuZhi= 1;  //竖直方向
    int  zhengXie = 1 ;//正斜方向
    int  fanXie = 1 ;//正斜方向
    
    
    //水平 向右检查
    //g_cursorY列的变化
    for(int i = 1; i < 5;i++)
    {
        
        if(g_cursorY + i < CHECKBROADSIZE && g_checkboard[g_cursorX][g_cursorY+i]==g_currentGamer)
           shuiPing ++;
        else
           break;
    }
    
    //水平 向左检查
    for(int i = 1; i < 5;i++)
    {
        
        if(g_cursorY - i > 0 && g_checkboard[g_cursorX][g_cursorY-i]==g_currentGamer)
           shuiPing ++;
        else
           break;
    }
       
    //竖直 向下检查
    //g_cursorX行的变化
    for(int i = 1; i < 5;i++)
    {
        
        if(g_cursorX + i < CHECKBROADSIZE && g_checkboard[g_cursorX+i][g_cursorY]==g_currentGamer)
           shuZhi ++;
        else
           break;
    }
    //竖直 向上检查
    for(int i = 1; i < 5;i++)
    {
        
        if(g_cursorX - i > 0 && g_checkboard[g_cursorX-i][g_cursorY]==g_currentGamer)
           shuZhi ++;
        else
           break;
    }
       
    //水平 向右检查
    //g_cursorY列的变化
    for(int i = 1; i < 5;i++)
    {
        
        if(g_cursorY + i < CHECKBROADSIZE && g_checkboard[g_cursorX][g_cursorY+i]==g_currentGamer)
           shuiPing ++;
        else
           break;
    }
    
    //正斜 左上检查
    for(int i = 1; i < 5;i++)
    {
        
        if(g_cursorX - i > 0 && g_cursorY - i >0&& g_checkboard[g_cursorX-i][g_cursorY-i]==g_currentGamer)
           zhengXie ++;
        else
           break;
    }
       
    //正斜 右下检查
    for(int i = 1; i < 5;i++)
    {
        
        if(g_cursorX + i < CHECKBROADSIZE && g_cursorY + i < CHECKBROADSIZE&& g_checkboard[g_cursorX+i][g_cursorY+i]==g_currentGamer)
           zhengXie ++;
        else
           break;
    }
    
    //反斜 右上检查
    for(int i = 1; i < 5;i++)
    {
        
        if(g_cursorX - i >0 && g_cursorY + i < CHECKBROADSIZE && g_checkboard[g_cursorX-i][g_cursorY+i]==g_currentGamer)
           fanXie ++;
        else
           break;
    }
       
    //反斜 左下检查
    for(int i = 1; i < 5;i++)
    {
        
        if(g_cursorX + i < CHECKBROADSIZE && g_cursorY - i > 0&& g_checkboard[g_cursorX+i][g_cursorY-i]==g_currentGamer)
           fanXie ++;
        else
           break;
    }
       
    if(shuZhi  >= 5 || shuiPing >= 5 || zhengXie >= 5 || fanXie >= 5)
       return g_currentGamer;
    return 0;
}
