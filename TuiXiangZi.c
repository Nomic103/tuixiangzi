//
//                                                                                     012345678901234567
//                                                                                   0 ##################
//                                                                                   1 #   R            #
//                                                                                   2 #                #
//                                                                                   3 #        0       #
//                                                                                   4 #                #
//                                                                                   5 #                #
//                                                                                   6 #          O     #
//                                                                                   7 #                #
//                                                                                   8 ##################
#include<stdio.h>
#include<conio.h>
#include<windows.h>

void printMap(char map[25][80], int hang, int lie);

int main()
{

                            //==========================================================================================
                            //====================================进入新手教程===========================================
                            //==========================================================================================
    //1.初始化地图
    const int hang = 25, lie = 80;
    char map[hang][lie];
    int i,j;
    int nier = 0;
    int hangZuoBiao = 1, lieZuoBiao = 4;//初始化小人坐标
    int xiangZiHangZuoBiao = 22, xiangZiLieZuoBiao = 72;//初始化箱子坐标
    int DongHangZuoBiao = 12, DongLieZuoBiao = 39;//初始化洞坐标
    //第一层初始化:先全部初始化为#
    for(i = 0; i < hang; i ++)
    {
        for(j = 0; j < lie; j ++)
        {
            map[i][j] = '#';
        }
    }
    //printMap(map, hang, lie);
    //第二层初始化:内圈全部赋值为空格
    for(i = 1; i < hang - 1; i ++)
    {
        for(j = 1; j < lie - 1; j ++)
        {
            map[i][j] = ' ';
        }
    }
//
    for(i = 4; i < hang - 4; i ++)
    {
        for(j = 4; j < lie - 4; j ++)
        {
            map[i][j] = '#';
        }
    }


    for(i = 5; i < hang - 5; i ++)
        {
            for(j = 5; j < lie - 5; j ++)
            {
                map[i][j] = ' ';
            }
        }

    for(i = 6; i < hang - 6; i ++)
    {
        for(j = 6; j < lie - 6; j ++)
        {
            map[i][j] = '#';
        }
    }

    for(i = 7; i < hang - 7; i ++)
    {
        for(j = 7; j < lie - 7; j ++)
        {
            map[i][j] = ' ';
        }
    }

    for(i = 9; i < hang - 9; i ++)
        {
            for(j = 9; j < lie - 15; j ++)
            {
                map[i][j] = '#';
            }
        }

    for(i = 10; i < hang - 10; i ++)
        {
            for(j = 10; j < lie - 16; j ++)
            {
                map[i][j] = ' ';
            }
        }

//
    // for(i = 0; i < hang; i ++)
    // {
    //     for(j = 0; j < lie; j ++)
    //     {
    //         map[i][j] = '#';
    //     }
    // }
    //printMap(map, hang, lie);
    //第三层初始化:精准赋值
    //人用R代替，箱子用D代替，坑用O代替
    map[hangZuoBiao][lieZuoBiao] = 'R';
    map[xiangZiHangZuoBiao][xiangZiLieZuoBiao] = 'D';
    map[DongHangZuoBiao][DongLieZuoBiao] = 'O';
    map[5][75] = ' ';
    map[10][75] = ' ';
    map[10][4] = ' ';
    map[15][44] = ' ';
    map[6][32] = ' ';
    map[4][32] = ' ';
    
    //输出地图
    printMap(map, hang, lie);
    //2.控制移动
    //输入wasd来移动
    do
    {
        printf("input w/a/s/d to move\n");
        char control;
        while(1)
        {
            //scanf("%c",&control);用getch函数实现输入数据后直接读取，不需要按回车（要调用conio.h库文件）
            control = getch();
            if(control == 'a' || control == 'w' || control == 's' || control == 'd')
            {
                break;
            }else if(control != '\n')
            {
                printf("illigal input , please input again\n");
            }
        }
        //小人移动，可以通过数组下标变换实现
        //输入a：列坐标-1；d：列坐标+1；w：行坐标-1；s：行坐标+1
        //限制移动的方法：当小人将要移动到的位置是#的时候，不允许移动
        switch(control)//<-----------------------------------------------------------------最容易出Bug的代码段
        {
            case 'w':
            if(map[hangZuoBiao - 1][lieZuoBiao] == 'D' && map[xiangZiHangZuoBiao - 1][xiangZiLieZuoBiao] != '#')
            {
                hangZuoBiao --;
                xiangZiHangZuoBiao --;
                map[hangZuoBiao][lieZuoBiao] = 'R';
                map[hangZuoBiao + 1][lieZuoBiao] = ' ';
                map[hangZuoBiao - 1][lieZuoBiao] = 'D';
            }
            else if(map[hangZuoBiao - 1][lieZuoBiao] != '#' && map[hangZuoBiao - 1][lieZuoBiao] != 'D')
            {
                hangZuoBiao --;
                map[hangZuoBiao][lieZuoBiao] = 'R';
                map[hangZuoBiao + 1][lieZuoBiao] = ' ';
            }
            break;
            case 's':
            if(map[hangZuoBiao + 1][lieZuoBiao] == 'D' && map[xiangZiHangZuoBiao + 1][xiangZiLieZuoBiao] != '#')
            {
                hangZuoBiao ++;
                xiangZiHangZuoBiao ++;
                map[hangZuoBiao][lieZuoBiao] = 'R';
                map[hangZuoBiao - 1][lieZuoBiao] = ' ';
                map[hangZuoBiao + 1][lieZuoBiao] = 'D';
            }
            else if(map[hangZuoBiao + 1][lieZuoBiao] != '#' && map[hangZuoBiao + 1][lieZuoBiao] != 'D')
            {
                hangZuoBiao ++;
                map[hangZuoBiao][lieZuoBiao] = 'R';
                map[hangZuoBiao - 1][lieZuoBiao] = ' ';
            }
            break;
            case 'a':
            if(map[hangZuoBiao][lieZuoBiao - 1] == 'D' && map[xiangZiHangZuoBiao][xiangZiLieZuoBiao - 1] != '#')
            {
                lieZuoBiao --;
                xiangZiLieZuoBiao --;
                map[hangZuoBiao][lieZuoBiao] = 'R';
                map[hangZuoBiao][lieZuoBiao + 1] = ' ';
                map[hangZuoBiao][lieZuoBiao - 1] = 'D';
            }
            else if(map[hangZuoBiao][lieZuoBiao - 1] != '#' && map[hangZuoBiao][lieZuoBiao - 1] != 'D')
            {
                lieZuoBiao --;
                map[hangZuoBiao][lieZuoBiao] = 'R';
                map[hangZuoBiao][lieZuoBiao + 1] = ' ';
            }
            break;
            case 'd':
            if(map[hangZuoBiao][lieZuoBiao + 1] == 'D' && map[xiangZiHangZuoBiao][xiangZiLieZuoBiao + 1] != '#')
            {
                lieZuoBiao ++;
                xiangZiLieZuoBiao ++;
                map[hangZuoBiao][lieZuoBiao] = 'R';
                map[hangZuoBiao][lieZuoBiao - 1] = ' ';
                map[hangZuoBiao][lieZuoBiao + 1] = 'D';
            }
            else if(map[hangZuoBiao][lieZuoBiao + 1] != '#' && map[hangZuoBiao][lieZuoBiao + 1] != 'D')
            {
                lieZuoBiao ++;
                map[hangZuoBiao][lieZuoBiao] = 'R';
                map[hangZuoBiao][lieZuoBiao - 1] = ' ';
            }
            break;
        }
        system("cls");
        printMap(map, hang, lie);
    }while(map[xiangZiHangZuoBiao][xiangZiLieZuoBiao] != map[DongHangZuoBiao][DongLieZuoBiao]);
    printf("congratulations!\n");
    system("pause");
}

void printMap(char map[25][80], int hang, int lie)
{
    int i = 0, j = 0, nier = 0;
    for(i = 0;i < hang; i ++)
    {
        for(j = 0; j < lie; j ++)
        {
            printf("%c",map[i][j]);
            nier ++;
            if(nier == 80)
            {
                printf("\n");
                nier = 0;
            }
        }
    }
}


