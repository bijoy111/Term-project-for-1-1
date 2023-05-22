# include "iGraphics.h"
#include<stdio.h>
#include<windows.h>
#include<MMsystem.h>
#include<math.h>
#include<stdlib.h>
void read();
FILE* fptr;
int gamestate=(-1);
int screenwidth= 1280, screenheight= 720;
/*
	function iDraw() is called again and again by the system.
*/
struct buttoncordinate
{
    int x;
    int y;
} bcordinate[5];
struct highs
{
    int score;
    char name[100]= {};
} highscore[10];
char button[30][30]= {"start.bmp","resume.bmp","highscore.bmp","help.bmp","exit.bmp"};
char gameover[20][30]= {"gameover.bmp"};
char rleft[20][30]= {"3.bmp","4.bmp"};
char  rright[20][30]= {"1.bmp","2.bmp"};
char rup[20][30]= {"5.bmp","6.bmp"};
char rdown[20][30]= {"7.bmp","8.bmp"};
char blinkyright[20][30]= {"blinkyright.bmp"};
char blinkyleft[20][30]= {"blinkyleft.bmp"};
char blinkyup[20][30]= {"blinkyup.bmp"};
char blinkydown[20][30]= {"blinkydown.bmp"};
char pinkyright[20][30]= {"pinkyright.bmp"};
char pinkyleft[20][30]= {"pinkyleft.bmp"};
char pinkyup[20][30]= {"pinkyup.bmp"};
char pinkydown[20][30]= {"pinkydown.bmp"};
char inkyright[20][30]= {"inkyright.bmp"};
char inkyleft[20][30]= {"inkyleft.bmp"};
char inkyup[20][30]= {"inkyup.bmp"};
char inkydown[20][30]= {"inkydown.bmp"};
char clyderight[20][30]= {"clyderight.bmp"};
char clydeleft[20][30]= {"clydeleft.bmp"};
char clydeup[20][30]= {"clydeup.bmp"};
char clydedown[20][30]= {"clydedown.bmp"};
char frozen[20][30]= {"frozenghost.bmp"};
int blinkyl=1;
int blinkyr=0;
int blinkyu=0;
int blinkyd=0;
int pinkyl=0;
int pinkyr=1;
int pinkyu=0;
int pinkyd=0;
int inkyl=1;
int inkyr=0;
int inkyu=0;
int inkyd=0;
int clydel=0;
int clyder=1;
int clydeu=0;
int clyded=0;
int blinkyx=880;
int blinkyy=600;
int pinkyx=320;
int pinkyy=600;
int inkyx=840;
int inkyy=40;
int clydex=360;
int clydey=40;
int px=600,py=320;
int posx=(px-320)/40,posy=14-((py-40)/40);
int pleft=0;
int pright=0;
int pup=0;
int pdown=0;
int ileft=0;//index
int iright=0;
int iup=0;
int idown=0;
int posblinkyx;
int posblinkyy;
int pospinkyx;
int pospinkyy;
int targetpinkyx;
int targetpinkyy;
int targetclydex;
int targetclydey;
int posinkyx;
int posinkyy;
int posclydex;
int posclydey;
int pacmanlive=3;
int mode=0;
char str[100];
char ara[100];
int gametime=60;
int score=0;
int s,t;
int flag=0;
int index=0;
char tex[100]= {};
int ar=0;
int enter=0;
int ind=0;
int dot=140;
int maze[15][15]=
{
    {3,1,1,1,1,1,1,1,1,1,1,1,1,1,3},
    {1,2,2,1,2,2,2,1,2,2,2,1,2,2,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,1,2,2,1,2,2,2,1,2,2,1,2,1},
    {1,1,1,1,2,1,2,2,2,1,2,1,1,1,1},
    {2,2,2,1,2,1,1,2,1,1,2,1,2,2,2},
    {2,2,2,1,1,1,1,1,1,1,1,1,2,2,2},
    {1,1,1,1,2,1,1,0,1,1,2,1,1,1,1},
    {1,2,2,1,2,1,1,1,1,1,2,1,2,2,1},
    {1,2,2,1,2,2,2,1,2,2,2,1,2,2,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,1,2,2,2,2,2,1,2,2,2,1},
    {1,1,2,1,1,1,1,2,1,1,1,1,2,1,1},
    {3,1,1,1,2,2,1,2,1,2,2,1,1,1,3},
    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,2}
};
int tmp[15][15]=
{
    {3,1,1,1,1,1,1,1,1,1,1,1,1,1,3},
    {1,2,2,1,2,2,2,1,2,2,2,1,2,2,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,1,2,2,1,2,2,2,1,2,2,1,2,1},
    {1,1,1,1,2,1,2,2,2,1,2,1,1,1,1},
    {2,2,2,1,2,1,1,2,1,1,2,1,2,2,2},
    {2,2,2,1,1,1,1,1,1,1,1,1,2,2,2},
    {1,1,1,1,2,1,1,0,1,1,2,1,1,1,1},
    {1,2,2,1,2,1,1,1,1,1,2,1,2,2,1},
    {1,2,2,1,2,2,2,1,2,2,2,1,2,2,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,1,2,2,2,2,2,1,2,2,2,1},
    {1,1,2,1,1,1,1,2,1,1,1,1,2,1,1},
    {3,1,1,1,2,2,1,2,1,2,2,1,1,1,3},
    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,2}
};
void iDraw()
{
    //place your drawing codes here

    iClear();

    if(gamestate==(-1))
    {
        iShowBMP(0,0,"C:\\Users\\ASUS\\OneDrive\\Pictures\\homepage.bmp");
        for(int i=0; i<5; i++)
        {
            iShowBMP(bcordinate[i].x,bcordinate[i].y,button[i]);
        }
    }
    if(gamestate==0)
    {
        iShowBMP(50,screenheight-100,"home start.bmp");
        iShowBMP(50,screenheight-200,"pause start.bmp");
        iRectangle(320,40,600,600);
        for(int i=14,m=40; i>=0; i--,m+=40)
        {
            for(int j=0,n=320; j<15; j++,n+=40)
            {
                if(maze[i][j]==2)
                {
                    iShowBMP(n,m,"C:\\Users\\ASUS\\OneDrive\\Pictures\\wall.bmp");
                }
                else if(maze[i][j]==1)
                {
                    iFilledCircle(n+20,m+20,5);
                }
                else if(maze[i][j]==3)
                {
                    iSetColor(255,0,0);
                    iFilledCircle(n+20,m+20,10);
                    iSetColor(255,255,255);
                }
            }
        }
        if(pdown==1)
        {
            iShowBMP2(px,py,rdown[idown],0);
        }
        else if(pleft==1)
        {
            iShowBMP2(px,py,rleft[ileft],0);
        }
        else if(pup==1)
        {
            iShowBMP2(px,py,rup[iup],0);
        }
        else
        {
            iShowBMP2(px,py,rright[iright],0);
        }
        if(mode==0)
        {
            if(blinkyl==1)
            {
                iShowBMP2(blinkyx,blinkyy,blinkyleft[0],0);
            }
            else if(blinkyr==1)
            {
                iShowBMP2(blinkyx,blinkyy,blinkyright[0],0);
            }
            else if(blinkyu==1)
            {
                iShowBMP2(blinkyx,blinkyy,blinkyup[0],0);
            }
            else
            {
                iShowBMP2(blinkyx,blinkyy,blinkydown[0],0);
            }
            if(pinkyl==1)
            {
                iShowBMP2(pinkyx,pinkyy,pinkyleft[0],0);
            }
            else if(pinkyr==1)
            {
                iShowBMP2(pinkyx,pinkyy,pinkyright[0],0);
            }
            else if(pinkyu==1)
            {
                iShowBMP2(pinkyx,pinkyy,pinkyup[0],0);
            }
            else
            {
                iShowBMP2(pinkyx,pinkyy,pinkydown[0],0);
            }
            if(inkyl==1)
            {
                iShowBMP2(inkyx,inkyy,inkyleft[0],0);
            }
            else if(inkyr==1)
            {
                iShowBMP2(inkyx,inkyy,inkyright[0],0);
            }
            else if(inkyu==1)
            {
                iShowBMP2(inkyx,inkyy,inkyup[0],0);
            }
            else
            {
                iShowBMP2(inkyx,inkyy,inkydown[0],0);
            }
            if(clydel==1)
            {
                iShowBMP2(clydex,clydey,clydeleft[0],0);
            }
            else if(clyder==1)
            {
                iShowBMP2(clydex,clydey,clyderight[0],0);
            }
            else if(clydeu==1)
            {
                iShowBMP2(clydex,clydey,clydeup[0],0);
            }
            else
            {
                iShowBMP2(clydex,clydey,clydedown[0],0);
            }
        }
        else if(mode==1)
        {
            iShowBMP2(blinkyx,blinkyy,frozen[0],0);
            iShowBMP2(pinkyx,pinkyy,frozen[0],0);
            iShowBMP2(inkyx,inkyy,frozen[0],0);
            iShowBMP2(clydex,clydey,frozen[0],0);
        }
        int add=320;
        for(int k=0; k<pacmanlive; k++)
        {
            iShowBMP2(add,0,rright[1],0);
            add+=40;
        }
        sprintf(str,"TIMES REMAINING:%d",gametime,GLUT_BITMAP_TIMES_ROMAN_10);
        iSetColor(255,0,0);
        iText(320,660,str);
        sprintf(ara,"SCORE:%d",score,GLUT_BITMAP_TIMES_ROMAN_10);
        iSetColor(255,0,0);
        iText(500,660,ara);
        iSetColor(255,255,255);
        if((gametime<=0||pacmanlive<=0||dot<=0))
        {
            gamestate=5;
            PlaySound(0,0,0);
            PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\gameover.wav"),NULL,SND_ASYNC);
        }
    }
    if(gamestate==1)
    {
        iShowBMP(50,screenheight-100,"home start.bmp");
        iShowBMP(50,screenheight-200,"pause start.bmp");
        iRectangle(320,40,600,600);
        for(int i=14,m=40; i>=0; i--,m+=40)
        {
            for(int j=0,n=320; j<15; j++,n+=40)
            {
                if(maze[i][j]==2)
                {
                    iShowBMP(n,m,"C:\\Users\\ASUS\\OneDrive\\Pictures\\wall.bmp");
                }
                else if(maze[i][j]==1)
                {
                    iSetColor(255,255,255);
                    iFilledCircle(n+20,m+20,5);
                }
                else if(maze[i][j]==3)
                {
                    iSetColor(255,0,0);
                    iFilledCircle(n+20,m+20,10);
                    iSetColor(255,255,255);
                }
            }
        }
        if(pdown==1)
        {
            iShowBMP2(px,py,rdown[idown],0);
        }
        else if(pleft==1)
        {
            iShowBMP2(px,py,rleft[ileft],0);
        }
        else if(pup==1)
        {
            iShowBMP2(px,py,rup[iup],0);
        }
        else
        {
            iShowBMP2(px,py,rright[iright],0);
        }
        if(mode==0)
        {
            if(blinkyl==1)
            {
                iShowBMP2(blinkyx,blinkyy,blinkyleft[0],0);
            }
            else if(blinkyr==1)
            {
                iShowBMP2(blinkyx,blinkyy,blinkyright[0],0);
            }
            else if(blinkyu==1)
            {
                iShowBMP2(blinkyx,blinkyy,blinkyup[0],0);
            }
            else
            {
                iShowBMP2(blinkyx,blinkyy,blinkydown[0],0);
            }
            if(pinkyl==1)
            {
                iShowBMP2(pinkyx,pinkyy,pinkyleft[0],0);
            }
            else if(pinkyr==1)
            {
                iShowBMP2(pinkyx,pinkyy,pinkyright[0],0);
            }
            else if(pinkyu==1)
            {
                iShowBMP2(pinkyx,pinkyy,pinkyup[0],0);
            }
            else
            {
                iShowBMP2(pinkyx,pinkyy,pinkydown[0],0);
            }
            if(inkyl==1)
            {
                iShowBMP2(inkyx,inkyy,inkyleft[0],0);
            }
            else if(inkyr==1)
            {
                iShowBMP2(inkyx,inkyy,inkyright[0],0);
            }
            else if(inkyu==1)
            {
                iShowBMP2(inkyx,inkyy,inkyup[0],0);
            }
            else
            {
                iShowBMP2(inkyx,inkyy,inkydown[0],0);
            }
            if(clydel==1)
            {
                iShowBMP2(clydex,clydey,clydeleft[0],0);
            }
            else if(clyder==1)
            {
                iShowBMP2(clydex,clydey,clyderight[0],0);
            }
            else if(clydeu==1)
            {
                iShowBMP2(clydex,clydey,clydeup[0],0);
            }
            else
            {
                iShowBMP2(clydex,clydey,clydedown[0],0);
            }
        }
        else if(mode==1)
        {
            iShowBMP2(blinkyx,blinkyy,frozen[0],0);
            iShowBMP2(pinkyx,pinkyy,frozen[0],0);
            iShowBMP2(inkyx,inkyy,frozen[0],0);
            iShowBMP2(clydex,clydey,frozen[0],0);
        }
        int add=320;
        for(int k=0; k<pacmanlive; k++)
        {
            iShowBMP2(add,0,rright[1],0);
            add+=40;
        }
        sprintf(str,"TIMES REMAINING:%d",gametime,GLUT_BITMAP_TIMES_ROMAN_10);
        iSetColor(255,0,0);
        iText(320,660,str);
        sprintf(ara,"SCORE:%d",score,GLUT_BITMAP_TIMES_ROMAN_10);
        iSetColor(255,0,0);
        iText(500,660,ara);
        if((gametime<=0||pacmanlive<=0))
        {
            gamestate=5;
            PlaySound(0,0,0);
            PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\gameover.wav"),NULL,SND_ASYNC);
        }
    }
    if(gamestate==2)
    {
        iShowBMP(0,0,"C:\\Users\\ASUS\\OneDrive\\Pictures\\highscorepage2.bmp");
        iShowBMP(50,screenheight-100,"home start.bmp");
        int sum=660;
        for(int i=0; i<ind&&i<10; i++)
        {
            char nam[100];
            char na[100];
            sprintf(nam,"%d",highscore[i].score,GLUT_BITMAP_TIMES_ROMAN_24);
            sprintf(na,"%d.",i+1,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(800,sum,nam);
            iText(600,sum,highscore[i].name);
            iText(550,sum,na);
            sum-=50;
        }
    }
    if(gamestate==5)
    {
        iShowBMP(0,0,gameover[0]);
        sprintf(ara,"YOUR SCORE IS: %d",score,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,0,0);
        iText(500,660,ara);
        iText(500,600,"ENTER YOUR NAME:");
        iSetColor(255,255,255);
        if(flag==0)
        {
            iRectangle(640,590,200,30);
        }
        else if(flag==1)
        {
            iSetColor(255,0,0);
            iRectangle(640,590,200,30);
            iText(650,600,tex);
            iSetColor(255,255,255);
        }
        iShowBMP(50,screenheight-100,"home start.bmp");
    }
    if(gamestate==3)
    {
        iShowBMP(50,screenheight-100,"home start.bmp");
        iText(50,screenheight-200,"DO NOT MAXIMIZE THE SCREEN.");
        iText(50,screenheight-250,"USE LEFT,RIGHT,UP,DOWN KEY TO MOVE THE PACMAN.");
        iText(50,screenheight-300,"PACMAN NEED TO EAT THE ALL DOTS TO WIN");
        iText(50,screenheight-350,"IN FOUR CORNER THERE ARE 4 RED POWER PELLET ,WHICH WHEN PACMAN EAT ONE THE GHOST WILL TURN BLUE.");
        iText(50,screenheight-400,"THERE ARE THREE LIVES OF PACMAN AND 60 MINIUTE TIME TO FINISH THE GAME.");
        iText(50,screenheight-450,"PACMAN GET 10 POINT FOR EAT DOT, 100 POINT TO EAT POWER PELLET AND 200 POINT TO EAT GHOST WHEN THEY ARE BLUE.");
        iText(50,screenheight-500,"IF PACMAN TOUCH THE GHOST WHEN THEY ARE NOT BLUE THEN PACMAN LOST ONE LIVE.");
    }
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(gamestate==(-1))
        {
            PlaySound(TEXT("C:\\Users\\ASUS\\Music\\song.wav"),NULL,SND_LOOP|SND_ASYNC);
            for(int i=0; i<5; i++)
            {
                if(mx>=bcordinate[i].x&&mx<=(bcordinate[i].x+250)&&my>=bcordinate[i].y&&my<=(bcordinate[i].y+50))
                {
                    Beep(400,500);
                    gamestate=i;
                }
            }
            if(gamestate==1)
                read();
        }
        if(gamestate==0)
        {
            enter=0;
            flag=0;
            index=0;
            blinkyl=1;
            blinkyr=0;
            blinkyu=0;
            blinkyd=0;
            pinkyl=0;
            pinkyr=1;
            pinkyu=0;
            pinkyd=0;
            inkyl=1;
            inkyr=0;
            inkyu=0;
            inkyd=0;
            clydel=0;
            clyder=1;
            clydeu=0;
            clyded=0;
            blinkyx=880;
            blinkyy=600;
            pinkyx=320;
            pinkyy=600;
            inkyx=840;
            inkyy=40;
            clydex=360;
            clydey=40;
            px=600,py=320;
            posx=(px-320)/40,posy=14-((py-40)/40);
            pleft=0;
            pright=0;
            pup=0;
            pdown=0;
            ileft=0;//index
            iright=0;
            iup=0;
            idown=0;
            pacmanlive=3;
            mode=0;
            gametime=60;
            score=0;
            dot=140;
            for(int i=0; i<15; i++)
            {
                for(int j=0; j<15; j++)
                {
                    maze[i][j]=tmp[i][j];
                }
            }
            PlaySound(0,0,0);
            PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\intro.wav"),NULL,SND_ASYNC);
            if(mx>=50&&mx<=150&&my>=620&&my<=660)
            {
                PlaySound(0,0,0);
                PlaySound(TEXT("C:\\Users\\ASUS\\Music\\song.wav"),NULL,SND_LOOP|SND_ASYNC);
                Beep(400,500);
                iPauseTimer(0);
                gamestate=(-1);
            }
            else if(mx>=50&&mx<=150&&my>=520&&my<=560)
            {
                PlaySound(0,0,0);
                PlaySound(TEXT("C:\\Users\\ASUS\\Music\\song.wav"),NULL,SND_LOOP|SND_ASYNC);
                Beep(400,500);
                iPauseTimer(0);
                gamestate=(-1);
            }
        }
        if(gamestate==1)
        {
            PlaySound(0,0,0);
            iResumeTimer(0);
            if(mx>=50&&mx<=150&&my>=620&&my<=660)
            {
                PlaySound(0,0,0);
                PlaySound(TEXT("C:\\Users\\ASUS\\Music\\song.wav"),NULL,SND_LOOP|SND_ASYNC);
                Beep(400,500);
                iPauseTimer(0);
                gamestate=(-1);
            }
            else if(mx>=50&&mx<=150&&my>=520&&my<=560)
            {
                PlaySound(0,0,0);
                PlaySound(TEXT("C:\\Users\\ASUS\\Music\\song.wav"),NULL,SND_LOOP|SND_ASYNC);
                Beep(400,500);
                iPauseTimer(0);
                gamestate=(-1);
            }
        }
        if(gamestate==2)
        {
            PlaySound(TEXT("C:\\Users\\ASUS\\Music\\song.wav"),NULL,SND_LOOP|SND_ASYNC);
            if(mx>=50&&mx<=150&&my>=620&&my<=660)
            {
                Beep(400,500);
                gamestate=(-1);
            }
        }
        if(gamestate==5)
        {
            PlaySound(0,0,0);
            //PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\gameover.wav"),NULL,SND_ASYNC);
            PlaySound(TEXT("C:\\Users\\ASUS\\Music\\song.wav"),NULL,SND_LOOP|SND_ASYNC);
            if(mx>=50&&mx<=150&&my>=620&&my<=660)
            {
                Beep(400,500);
                gamestate=(-1);//640,590,200,30
                highscore[ind].score=score;
                int k=0;
                for(k=0; tex[k]!='\0'; k++)
                {
                    highscore[ind].name[k]=tex[k];
                }
                highscore[ind].name[k]='\0';
                ind++;
                FILE* f;
                f=fopen("saeem.txt","w");
                for (int i = 0; i < ind; i++)
                {
                    for (int j = 0; j < ind; j++)
                    {
                        if (highscore[j].score < highscore[i].score)
                        {
                            int tmp = highscore[i].score;
                            highscore[i].score =highscore[j].score;
                            highscore[j] .score= tmp;
                            char t[100];
                            strcpy(t,highscore[i].name);
                            strcpy(highscore[i].name,highscore[j].name);
                            strcpy(highscore[j].name,t);
                        }
                    }
                }
                for (int i = 0; i < ind; i++)
                {
                    fprintf(f,"%d %s\n", highscore[i].score,highscore[i].name);
                }
                fclose(f);
                tex[0]=NULL;
                enter=1;
                flag=1;
            }
            if(mx>=640&&mx<=840&&my>=590&&my<=620)
                flag=1;
        }
        if(gamestate==3)
        {
            PlaySound(0,0,0);
            PlaySound(TEXT("C:\\Users\\ASUS\\Music\\song.wav"),NULL,SND_LOOP|SND_ASYNC);
            if(mx>=50&&mx<=150&&my>=620&&my<=660)
            {
                Beep(400,500);
                gamestate=(-1);
            }
        }
        if(gamestate==4)
        {
            exit(0);
        }
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}
/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(gamestate==5&&flag==1)
    {
        if(key!='\b')
        {
            tex[index]=key;
            index++;
            tex[index]='\0';
        }
        else
        {
            if(index<=0)
                index=0;
            else
            {
                index--;
            }
            tex[index]='\0';
        }
    }
    if(key == 'q')
    {
        exit(0);
    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_LEFT)
    {
        posx=(px-320)/40;
        posy=14-((py-40)/40);
        if(maze[posy][posx-1]==1||maze[posy][posx-1]==0||maze[posy][posx-1]==3)
        {
            if((px-40)>=320)
            {
                px-=40;
                pleft=1;
                pright=0;
                pup=0;
                pdown=0;
                if(maze[posy][posx-1]==1)
                {
                    //Beep(300,50);
                    //PlaySound(0,0,0);
                    //PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\attack.wav"),NULL,SND_ASYNC);
                    dot--;
                    score+=10;
                    maze[posy][posx-1]=0;
                }
                if(maze[posy][posx-1]==3)
                {
                    dot--;
                    PlaySound(0,0,0);
                    PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\fruit.wav"),NULL,SND_ASYNC);
                    score+=100;
                    maze[posy][posx-1]=0;
                    mode=1;
                    s=200;
                    t=0;
                }
            }
        }
    }
    if(key == GLUT_KEY_RIGHT)
    {
        posx=(px-320)/40;
        posy=14-((py-40)/40);
        if(maze[posy][posx+1]==1||maze[posy][posx+1]==0||maze[posy][posx+1]==3)
        {
            if((px+40)<=880)
            {
                px+=40;
                pleft=0;
                pright=1;
                pup=0;
                pdown=0;
                if(maze[posy][posx+1]==1)
                {
                    dot--;
                    //Beep(300,50);
                    //PlaySound(0,0,0);
                    //PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\attack.wav"),NULL,SND_ASYNC);
                    score+=10;
                    maze[posy][posx+1]=0;
                }
                if(maze[posy][posx+1]==3)
                {
                    dot--;
                    PlaySound(0,0,0);
                    PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\ghost.wav"),NULL,SND_ASYNC);
                    score+=100;
                    maze[posy][posx+1]=0;
                    mode=1;
                    s=200;
                    t=0;
                }
            }
        }
    }
    if(key == GLUT_KEY_UP)
    {
        posx=(px-320)/40;
        posy=14-((py-40)/40);
        if(maze[posy-1][posx]==1||maze[posy-1][posx]==0||maze[posy-1][posx]==3)
        {
            if((py+40)<=600)
            {
                py+=40;
                pleft=0;
                pright=0;
                pup=1;
                pdown=0;
                if(maze[posy-1][posx]==1)
                {
                    dot--;
                    //Beep(300,50);
                    //PlaySound(0,0,0);
                    //PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\attack.wav"),NULL,SND_ASYNC);
                    score+=10;
                    maze[posy-1][posx]=0;
                }
                if(maze[posy-1][posx]==3)
                {
                    dot--;
                    PlaySound(0,0,0);
                    PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\ghost.wav"),NULL,SND_ASYNC);
                    score+=100;
                    maze[posy-1][posx]=0;
                    mode=1;
                    s=200;
                    t=0;
                }
            }
        }
    }
    if(key == GLUT_KEY_DOWN)
    {
        posx=(px-320)/40;
        posy=14-(py-40)/40;
        if(maze[posy+1][posx]==1||maze[posy+1][posx]==0||maze[posy+1][posx]==3)
        {
            if((py-40)>=40)
            {
                py-=40;
                pleft=0;
                pright=0;
                pup=0;
                pdown=1;
                if(maze[posy+1][posx]==1)
                {
                    dot--;
                    //Beep(300,50);
                    score+=10;
                    maze[posy+1][posx]=0;
                }
                if(maze[posy+1][posx]==3)
                {
                    dot--;
                    PlaySound(0,0,0);
                    PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\ghost.wav"),NULL,SND_ASYNC);
                    score+=100;
                    maze[posy+1][posx]=0;
                    mode=1;
                    s=200;
                    t=0;
                }
            }
        }
    }
    //place your codes for other keys here
}
void pacmanchange()
{
    if(pleft==1)
    {
        if(ileft==0)
            ileft=1;
        else
            ileft=0;
    }
    else if(pright==1)
    {
        if(iright==0)
            iright=1;
        else
            iright=0;
    }
    else if(pup==1)
    {
        if(iup==0)
            iup=1;
        else
            iup=0;
    }
    else if(pdown==1)
    {
        if(idown==0)
            idown=1;
        else
            idown=0;
    }
}
void blinkychange()
{
    if(gamestate==0||gamestate==1)
    {
        posblinkyx=(blinkyx-320)/40;//14
        posblinkyy=14-((blinkyy-40)/40);//0
        if(mode==0)
        {
            if(blinkyl==1)
            {
                int l=400,u=400,d=400;
                if((blinkyx-40)>=320&&maze[posblinkyy][posblinkyx-1]!=2)
                {
                    int a=abs(posx-(posblinkyx-1));
                    int b=abs(posy-posblinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if((blinkyy+40)<=600&&maze[posblinkyy-1][posblinkyx]!=2)
                {
                    int a=abs(posx-posblinkyx);
                    int b=abs(posy-(posblinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((blinkyy-40)>=40&&maze[posblinkyy+1][posblinkyx]!=2)
                {
                    int a=abs(posx-posblinkyx);
                    int b=abs(posy-(posblinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u<=l&&u<=d)
                {
                    blinkyy+=40;
                    blinkyl=0;
                    blinkyr=0;
                    blinkyu=1;
                    blinkyd=0;
                }
                else if(l<=d&&l<=u)
                {
                    blinkyx-=40;
                    blinkyl=1;
                    blinkyr=0;
                    blinkyu=0;
                    blinkyd=0;
                }
                else
                {
                    blinkyy-=40;
                    blinkyl=0;
                    blinkyr=0;
                    blinkyu=0;
                    blinkyd=1;
                }
            }
            else if(blinkyr==1)
            {
                int r=400,u=400,d=400;
                if((blinkyx+40)<=880&&maze[posblinkyy][posblinkyx+1]!=2)
                {
                    int a=abs(posx-(posblinkyx+1));
                    int b=abs(posy-posblinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((blinkyy+40)<=600&&maze[posblinkyy-1][posblinkyx]!=2)
                {
                    int a=abs(posx-posblinkyx);
                    int b=abs(posy-(posblinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((blinkyy-40)>=40&&maze[posblinkyy+1][posblinkyx]!=2)
                {
                    int a=abs(posx-posblinkyx);
                    int b=abs(posy-(posblinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u<=r&&u<=d)
                {
                    blinkyy+=40;
                    blinkyl=0;
                    blinkyr=0;
                    blinkyu=1;
                    blinkyd=0;
                }
                else if(d<=u&&d<=r)
                {
                    blinkyy-=40;
                    blinkyl=0;
                    blinkyr=0;
                    blinkyu=0;
                    blinkyd=1;
                }
                else
                {
                    blinkyx+=40;
                    blinkyl=0;
                    blinkyr=1;
                    blinkyu=0;
                    blinkyd=0;
                }
            }
            else if(blinkyu==1)
            {
                int r=400,u=400,l=400;
                if((blinkyx+40)<=880&&maze[posblinkyy][posblinkyx+1]!=2)
                {
                    int a=abs(posx-(posblinkyx+1));
                    int b=abs(posy-posblinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((blinkyy+40)<=600&&maze[posblinkyy-1][posblinkyx]!=2)
                {
                    int a=abs(posx-posblinkyx);
                    int b=abs(posy-(posblinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((blinkyx-40)>=320&&maze[posblinkyy][posblinkyx-1]!=2)
                {
                    int a=abs(posx-(posblinkyx-1));
                    int b=abs(posy-posblinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if(u<=r&&u<=l)
                {
                    blinkyy+=40;
                    blinkyl=0;
                    blinkyr=0;
                    blinkyu=1;
                    blinkyd=0;
                }
                else if(l<=r&&l<=u)
                {
                    blinkyx-=40;
                    blinkyl=1;
                    blinkyr=0;
                    blinkyu=0;
                    blinkyd=0;
                }
                else
                {
                    blinkyx+=40;
                    blinkyl=0;
                    blinkyr=1;
                    blinkyu=0;
                    blinkyd=0;
                }
            }
            else if(blinkyd==1)
            {
                int r=400,d=400,l=400;
                if((blinkyx+40)<=880&&maze[posblinkyy][posblinkyx+1]!=2)
                {
                    int a=abs(posx-(posblinkyx+1));
                    int b=abs(posy-posblinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((blinkyy-40)>=40&&maze[posblinkyy+1][posblinkyx]!=2)
                {
                    int a=abs(posx-posblinkyx);
                    int b=abs(posy-(posblinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if((blinkyx-40)>=320&&maze[posblinkyy][posblinkyx-1]!=2)
                {
                    int a=abs(posx-(posblinkyx-1));
                    int b=abs(posy-posblinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if(l<=d&&l<=r)
                {
                    blinkyx-=40;
                    blinkyl=1;
                    blinkyr=0;
                    blinkyu=0;
                    blinkyd=0;
                }
                else if(d<=l&&d<=r)
                {
                    blinkyy-=40;
                    blinkyl=0;
                    blinkyr=0;
                    blinkyu=0;
                    blinkyd=1;
                }
                else
                {
                    blinkyx+=40;
                    blinkyl=0;
                    blinkyr=1;
                    blinkyu=0;
                    blinkyd=0;
                }
            }
        }
        else if(mode==1)
        {
            if(blinkyl==1)
            {
                int l=0,u=0,d=0;
                if((blinkyx-40)>=320&&maze[posblinkyy][posblinkyx-1]!=2)
                {
                    int a=abs(posx-(posblinkyx-1));
                    int b=abs(posy-posblinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if((blinkyy+40)<=600&&maze[posblinkyy-1][posblinkyx]!=2)
                {
                    int a=abs(posx-posblinkyx);
                    int b=abs(posy-(posblinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((blinkyy-40)>=40&&maze[posblinkyy+1][posblinkyx]!=2)
                {
                    int a=abs(posx-posblinkyx);
                    int b=abs(posy-(posblinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u>=l&&u>=d)
                {
                    blinkyy+=40;
                    blinkyl=0;
                    blinkyr=0;
                    blinkyu=1;
                    blinkyd=0;
                }
                else if(l>=d&&l>=u)
                {
                    blinkyx-=40;
                    blinkyl=1;
                    blinkyr=0;
                    blinkyu=0;
                    blinkyd=0;
                }
                else
                {
                    blinkyy-=40;
                    blinkyl=0;
                    blinkyr=0;
                    blinkyu=0;
                    blinkyd=1;
                }
            }
            else if(blinkyr==1)
            {
                int r=0,u=0,d=0;
                if((blinkyx+40)<=880&&maze[posblinkyy][posblinkyx+1]!=2)
                {
                    int a=abs(posx-(posblinkyx+1));
                    int b=abs(posy-posblinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((blinkyy+40)<=600&&maze[posblinkyy-1][posblinkyx]!=2)
                {
                    int a=abs(posx-posblinkyx);
                    int b=abs(posy-(posblinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((blinkyy-40)>=40&&maze[posblinkyy+1][posblinkyx]!=2)
                {
                    int a=abs(posx-posblinkyx);
                    int b=abs(posy-(posblinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u>=r&&u>=d)
                {
                    blinkyy+=40;
                    blinkyl=0;
                    blinkyr=0;
                    blinkyu=1;
                    blinkyd=0;
                }
                else if(d>=u&&d>=r)
                {
                    blinkyy-=40;
                    blinkyl=0;
                    blinkyr=0;
                    blinkyu=0;
                    blinkyd=1;
                }
                else
                {
                    blinkyx+=40;
                    blinkyl=0;
                    blinkyr=1;
                    blinkyu=0;
                    blinkyd=0;
                }
            }
            else if(blinkyu==1)
            {
                int r=0,u=0,l=0;
                if((blinkyx+40)<=880&&maze[posblinkyy][posblinkyx+1]!=2)
                {
                    int a=abs(posx-(posblinkyx+1));
                    int b=abs(posy-posblinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((blinkyy+40)<=600&&maze[posblinkyy-1][posblinkyx]!=2)
                {
                    int a=abs(posx-posblinkyx);
                    int b=abs(posy-(posblinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((blinkyx-40)>=320&&maze[posblinkyy][posblinkyx-1]!=2)
                {
                    int a=abs(posx-(posblinkyx-1));
                    int b=abs(posy-posblinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if(u>=r&&u>=l)
                {
                    blinkyy+=40;
                    blinkyl=0;
                    blinkyr=0;
                    blinkyu=1;
                    blinkyd=0;
                }
                else if(l>=r&&l>=u)
                {
                    blinkyx-=40;
                    blinkyl=1;
                    blinkyr=0;
                    blinkyu=0;
                    blinkyd=0;
                }
                else
                {
                    blinkyx+=40;
                    blinkyl=0;
                    blinkyr=1;
                    blinkyu=0;
                    blinkyd=0;
                }
            }
            else if(blinkyd==1)
            {
                int r=0,d=0,l=0;
                if((blinkyx+40)<=880&&maze[posblinkyy][posblinkyx+1]!=2)
                {
                    int a=abs(posx-(posblinkyx+1));
                    int b=abs(posy-posblinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((blinkyy-40)>=40&&maze[posblinkyy+1][posblinkyx]!=2)
                {
                    int a=abs(posx-posblinkyx);
                    int b=abs(posy-(posblinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if((blinkyx-40)>=320&&maze[posblinkyy][posblinkyx-1]!=2)
                {
                    int a=abs(posx-(posblinkyx-1));
                    int b=abs(posy-posblinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if(l>=d&&l>=r)
                {
                    blinkyx-=40;
                    blinkyl=1;
                    blinkyr=0;
                    blinkyu=0;
                    blinkyd=0;
                }
                else if(d>=l&&d>=r)
                {
                    blinkyy-=40;
                    blinkyl=0;
                    blinkyr=0;
                    blinkyu=0;
                    blinkyd=1;
                }
                else
                {
                    blinkyx+=40;
                    blinkyl=0;
                    blinkyr=1;
                    blinkyu=0;
                    blinkyd=0;
                }
            }
        }
    }
}
void pinkychange()
{
    if(gamestate==0||gamestate==1)
    {
        pospinkyx=(pinkyx-320)/40;//14
        pospinkyy=14-((pinkyy-40)/40);//0
        if(mode==0)
        {
            if(pleft==1)
            {
                targetpinkyx=posx-4;
                targetpinkyy=posy;
            }
            else if(pright==1)
            {
                targetpinkyx=posx+4;
                targetpinkyy=posy;
            }
            else if(pup==1)
            {
                targetpinkyx=posx;
                targetpinkyy=posy-4;
            }
            else
            {
                targetpinkyx=posx;
                targetpinkyy=posy+4;
            }
            if(pinkyl==1)
            {
                int l=400,u=400,d=400;
                if((pinkyx-40)>=320&&maze[pospinkyy][pospinkyx-1]!=2)
                {
                    int a=abs(targetpinkyx-(pospinkyx-1));
                    int b=abs(targetpinkyy-pospinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if((pinkyy+40)<=600&&maze[pospinkyy-1][pospinkyx]!=2)
                {
                    int a=abs(targetpinkyx-pospinkyx);
                    int b=abs(targetpinkyy-(pospinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((pinkyy-40)>=40&&maze[pospinkyy+1][pospinkyx]!=2)
                {
                    int a=abs(targetpinkyx-pospinkyx);
                    int b=abs(targetpinkyy-(pospinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u<=l&&u<=d)
                {
                    pinkyy+=40;
                    pinkyl=0;
                    pinkyr=0;
                    pinkyu=1;
                    pinkyd=0;
                }
                else if(l<=d&&l<=u)
                {
                    pinkyx-=40;
                    pinkyl=1;
                    pinkyr=0;
                    pinkyu=0;
                    pinkyd=0;
                }
                else
                {
                    pinkyy-=40;
                    pinkyl=0;
                    pinkyr=0;
                    pinkyu=0;
                    pinkyd=1;
                }
            }
            else if(pinkyr==1)
            {
                int r=400,u=400,d=400;
                if((pinkyx+40)<=880&&maze[pospinkyy][pospinkyx+1]!=2)
                {
                    int a=abs(targetpinkyx-(pospinkyx+1));
                    int b=abs(targetpinkyy-pospinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((pinkyy+40)<=600&&maze[pospinkyy-1][pospinkyx]!=2)
                {
                    int a=abs(targetpinkyx-pospinkyx);
                    int b=abs(targetpinkyy-(pospinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((pinkyy-40)>=40&&maze[pospinkyy+1][pospinkyx]!=2)
                {
                    int a=abs(targetpinkyx-pospinkyx);
                    int b=abs(targetpinkyy-(pospinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u<=r&&u<=d)
                {
                    pinkyy+=40;
                    pinkyl=0;
                    pinkyr=0;
                    pinkyu=1;
                    pinkyd=0;
                }
                else if(d<=u&&d<=r)
                {
                    pinkyy-=40;
                    pinkyl=0;
                    pinkyr=0;
                    pinkyu=0;
                    pinkyd=1;
                }
                else
                {
                    pinkyx+=40;
                    pinkyl=0;
                    pinkyr=1;
                    pinkyu=0;
                    pinkyd=0;
                }
            }
            else if(pinkyu==1)
            {
                int r=400,u=400,l=400;
                if((pinkyx+40)<=880&&maze[pospinkyy][pospinkyx+1]!=2)
                {
                    int a=abs(targetpinkyx-(pospinkyx+1));
                    int b=abs(targetpinkyy-pospinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((pinkyy+40)<=600&&maze[pospinkyy-1][pospinkyx]!=2)
                {
                    int a=abs(targetpinkyx-pospinkyx);
                    int b=abs(targetpinkyy-(pospinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((pinkyx-40)>=320&&maze[pospinkyy][pospinkyx-1]!=2)
                {
                    int a=abs(targetpinkyx-(pospinkyx-1));
                    int b=abs(targetpinkyy-pospinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if(u<=r&&u<=l)
                {
                    pinkyy+=40;
                    pinkyl=0;
                    pinkyr=0;
                    pinkyu=1;
                    pinkyd=0;
                }
                else if(l<=r&&l<=u)
                {
                    pinkyx-=40;
                    pinkyl=1;
                    pinkyr=0;
                    pinkyu=0;
                    pinkyd=0;
                }
                else
                {
                    pinkyx+=40;
                    pinkyl=0;
                    pinkyr=1;
                    pinkyu=0;
                    pinkyd=0;
                }
            }
            else if(pinkyd==1)
            {
                int r=400,d=400,l=400;
                if((pinkyx+40)<=880&&maze[pospinkyy][pospinkyx+1]!=2)
                {
                    int a=abs(targetpinkyx-(pospinkyx+1));
                    int b=abs(targetpinkyy-pospinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((pinkyy-40)>=40&&maze[pospinkyy+1][pospinkyx]!=2)
                {
                    int a=abs(targetpinkyx-pospinkyx);
                    int b=abs(targetpinkyy-(pospinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if((pinkyx-40)>=320&&maze[pospinkyy][pospinkyx-1]!=2)
                {
                    int a=abs(targetpinkyx-(pospinkyx-1));
                    int b=abs(targetpinkyy-pospinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if(l<=d&&l<=r)
                {
                    pinkyx-=40;
                    pinkyl=1;
                    pinkyr=0;
                    pinkyu=0;
                    pinkyd=0;
                }
                else if(d<=l&&d<=r)
                {
                    pinkyy-=40;
                    pinkyl=0;
                    pinkyr=0;
                    pinkyu=0;
                    pinkyd=1;
                }
                else
                {
                    pinkyx+=40;
                    pinkyl=0;
                    pinkyr=1;
                    pinkyu=0;
                    pinkyd=0;
                }
            }
        }
        else if(mode==1)
        {
            if(pleft==1)
            {
                targetpinkyx=posx-4;
                targetpinkyy=posy;
            }
            else if(pright==1)
            {
                targetpinkyx=posx+4;
                targetpinkyy=posy;
            }
            else if(pup==1)
            {
                targetpinkyx=posx;
                targetpinkyy=posy-4;
            }
            else
            {
                targetpinkyx=posx;
                targetpinkyy=posy+4;
            }
            if(pinkyl==1)
            {
                int l=0,u=0,d=0;
                if((pinkyx-40)>=320&&maze[pospinkyy][pospinkyx-1]!=2)
                {
                    int a=abs(targetpinkyx-(pospinkyx-1));
                    int b=abs(targetpinkyy-pospinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if((pinkyy+40)<=600&&maze[pospinkyy-1][pospinkyx]!=2)
                {
                    int a=abs(targetpinkyx-pospinkyx);
                    int b=abs(targetpinkyy-(pospinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((pinkyy-40)>=40&&maze[pospinkyy+1][pospinkyx]!=2)
                {
                    int a=abs(targetpinkyx-pospinkyx);
                    int b=abs(targetpinkyy-(pospinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u>=l&&u>=d)
                {
                    pinkyy+=40;
                    pinkyl=0;
                    pinkyr=0;
                    pinkyu=1;
                    pinkyd=0;
                }
                else if(l>=d&&l>=u)
                {
                    pinkyx-=40;
                    pinkyl=1;
                    pinkyr=0;
                    pinkyu=0;
                    pinkyd=0;
                }
                else
                {
                    pinkyy-=40;
                    pinkyl=0;
                    pinkyr=0;
                    pinkyu=0;
                    pinkyd=1;
                }
            }
            else if(pinkyr==1)
            {
                int r=0,u=0,d=0;
                if((pinkyx+40)<=880&&maze[pospinkyy][pospinkyx+1]!=2)
                {
                    int a=abs(targetpinkyx-(pospinkyx+1));
                    int b=abs(targetpinkyy-pospinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((pinkyy+40)<=600&&maze[pospinkyy-1][pospinkyx]!=2)
                {
                    int a=abs(targetpinkyx-pospinkyx);
                    int b=abs(targetpinkyy-(pospinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((pinkyy-40)>=40&&maze[pospinkyy+1][pospinkyx]!=2)
                {
                    int a=abs(targetpinkyx-pospinkyx);
                    int b=abs(targetpinkyy-(pospinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u>=r&&u>=d)
                {
                    pinkyy+=40;
                    pinkyl=0;
                    pinkyr=0;
                    pinkyu=1;
                    pinkyd=0;
                }
                else if(d>=u&&d>=r)
                {
                    pinkyy-=40;
                    pinkyl=0;
                    pinkyr=0;
                    pinkyu=0;
                    pinkyd=1;
                }
                else
                {
                    pinkyx+=40;
                    pinkyl=0;
                    pinkyr=1;
                    pinkyu=0;
                    pinkyd=0;
                }
            }
            else if(pinkyu==1)
            {
                int r=0,u=0,l=0;
                if((pinkyx+40)<=880&&maze[pospinkyy][pospinkyx+1]!=2)
                {
                    int a=abs(targetpinkyx-(pospinkyx+1));
                    int b=abs(targetpinkyy-pospinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((pinkyy+40)<=600&&maze[pospinkyy-1][pospinkyx]!=2)
                {
                    int a=abs(targetpinkyx-pospinkyx);
                    int b=abs(targetpinkyy-(pospinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((pinkyx-40)>=320&&maze[pospinkyy][pospinkyx-1]!=2)
                {
                    int a=abs(targetpinkyx-(pospinkyx-1));
                    int b=abs(targetpinkyy-pospinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if(u>=r&&u>=l)
                {
                    pinkyy+=40;
                    pinkyl=0;
                    pinkyr=0;
                    pinkyu=1;
                    pinkyd=0;
                }
                else if(l>=r&&l>=u)
                {
                    pinkyx-=40;
                    pinkyl=1;
                    pinkyr=0;
                    pinkyu=0;
                    pinkyd=0;
                }
                else
                {
                    pinkyx+=40;
                    pinkyl=0;
                    pinkyr=1;
                    pinkyu=0;
                    pinkyd=0;
                }
            }
            else if(pinkyd==1)
            {
                int r=0,d=0,l=0;
                if((pinkyx+40)<=880&&maze[pospinkyy][pospinkyx+1]!=2)
                {
                    int a=abs(targetpinkyx-(pospinkyx+1));
                    int b=abs(targetpinkyy-pospinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((pinkyy-40)>=40&&maze[pospinkyy+1][pospinkyx]!=2)
                {
                    int a=abs(targetpinkyx-pospinkyx);
                    int b=abs(targetpinkyy-(pospinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if((pinkyx-40)>=320&&maze[pospinkyy][pospinkyx-1]!=2)
                {
                    int a=abs(targetpinkyx-(pospinkyx-1));
                    int b=abs(targetpinkyy-pospinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if(l>=d&&l>=r)
                {
                    pinkyx-=40;
                    pinkyl=1;
                    pinkyr=0;
                    pinkyu=0;
                    pinkyd=0;
                }
                else if(d>=l&&d>=r)
                {
                    pinkyy-=40;
                    pinkyl=0;
                    pinkyr=0;
                    pinkyu=0;
                    pinkyd=1;
                }
                else
                {
                    pinkyx+=40;
                    pinkyl=0;
                    pinkyr=1;
                    pinkyu=0;
                    pinkyd=0;
                }
            }
        }
    }
}
void inkychange()
{
    if(gamestate==0||gamestate==1)
    {
        posinkyx=(inkyx-320)/40;//14
        posinkyy=14-((inkyy-40)/40);//0
        if(mode==0)
        {
            if(inkyl==1)
            {
                int l=400,u=400,d=400;
                if((inkyx-40)>=320&&maze[posinkyy][posinkyx-1]!=2&&(abs(posx-posinkyx+1)>=4||abs(posy-posinkyy)>=4))
                {
                    int a=abs(posx-(posinkyx-1));
                    int b=abs(posy-posinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if((inkyy+40)<=600&&maze[posinkyy-1][posinkyx]!=2)
                {
                    int a=abs(posx-posinkyx);
                    int b=abs(posy-(posinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((inkyy-40)>=40&&maze[posinkyy+1][posinkyx]!=2)
                {
                    int a=abs(posx-posinkyx);
                    int b=abs(posy-(posinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u==400&&l==400&&d==400)
                {
                    inkyx+=40;
                    inkyl=0;
                    inkyr=1;
                    inkyu=0;
                    inkyd=0;
                }
                else if(u<=l&&u<=d)
                {
                    inkyy+=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=1;
                    inkyd=0;
                }
                else if(l<=d&&l<=u)
                {
                    inkyx-=40;
                    inkyl=1;
                    inkyr=0;
                    inkyu=0;
                    inkyd=0;
                }
                else
                {
                    inkyy-=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=0;
                    inkyd=1;
                }
            }
            else if(inkyr==1)
            {
                int r=400,u=400,d=400;
                if((inkyx+40)<=880&&maze[posinkyy][posinkyx+1]!=2&&(abs(posx-posinkyx-1)>=4||abs(posy-posinkyy)>=4))
                {
                    int a=abs(posx-(posinkyx+1));
                    int b=abs(posy-posinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((inkyy+40)<=600&&maze[posinkyy-1][posinkyx]!=2)
                {
                    int a=abs(posx-posinkyx);
                    int b=abs(posy-(posinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((inkyy-40)>=40&&maze[posinkyy+1][posinkyx]!=2)
                {
                    int a=abs(posx-posinkyx);
                    int b=abs(posy-(posinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u==400&&r==400&&d==400)
                {
                    inkyx-=40;
                    inkyl=1;
                    inkyr=0;
                    inkyu=0;
                    inkyd=0;
                }
                else if(u<=r&&u<=d)
                {
                    inkyy+=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=1;
                    inkyd=0;
                }
                else if(d<=u&&d<=r)
                {
                    inkyy-=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=0;
                    inkyd=1;
                }
                else
                {
                    inkyx+=40;
                    inkyl=0;
                    inkyr=1;
                    inkyu=0;
                    inkyd=0;
                }
            }
            else if(inkyu==1)
            {
                int r=400,u=400,l=400;
                if((inkyx+40)<=880&&maze[posinkyy][posinkyx+1]!=2)
                {
                    int a=abs(posx-(posinkyx+1));
                    int b=abs(posy-posinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((inkyy+40)<=600&&maze[posinkyy-1][posinkyx]!=2&&(abs(posy-posinkyy+1)>=4||abs(posx-posinkyx)>=4))
                {
                    int a=abs(posx-posinkyx);
                    int b=abs(posy-(posinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((inkyx-40)>=320&&maze[posinkyy][posinkyx-1]!=2)
                {
                    int a=abs(posx-(posinkyx-1));
                    int b=abs(posy-posinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if(u==400&&r==400&&l==400)
                {
                    inkyy-=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=0;
                    inkyd=1;
                }
                else if(u<=r&&u<=l)
                {
                    inkyy+=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=1;
                    inkyd=0;
                }
                else if(l<=r&&l<=u)
                {
                    inkyx-=40;
                    inkyl=1;
                    inkyr=0;
                    inkyu=0;
                    inkyd=0;
                }
                else
                {
                    inkyx+=40;
                    inkyl=0;
                    inkyr=1;
                    inkyu=0;
                    inkyd=0;
                }
            }
            else if(inkyd==1)
            {
                int r=400,d=400,l=400;
                if((inkyx+40)<=880&&maze[posinkyy][posinkyx+1]!=2)
                {
                    int a=abs(posx-(posinkyx+1));
                    int b=abs(posy-posinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((inkyy-40)>=40&&maze[posinkyy+1][posinkyx]!=2&&(abs(posy-posinkyy-1)>=4||abs(posx-posinkyx)>=4))
                {
                    int a=abs(posx-posinkyx);
                    int b=abs(posy-(posinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if((inkyx-40)>=320&&maze[posinkyy][posinkyx-1]!=2)
                {
                    int a=abs(posx-(posinkyx-1));
                    int b=abs(posy-posinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if(l==400&&d==400&&r==400)
                {
                    inkyy+=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=1;
                    inkyd=0;
                }
                else if(l<=d&&l<=r)
                {
                    inkyx-=40;
                    inkyl=1;
                    inkyr=0;
                    inkyu=0;
                    inkyd=0;
                }
                else if(d<=l&&d<=r)
                {
                    inkyy-=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=0;
                    inkyd=1;
                }
                else
                {
                    inkyx+=40;
                    inkyl=0;
                    inkyr=1;
                    inkyu=0;
                    inkyd=0;
                }
            }
        }
        else if(mode==1)
        {
            if(inkyl==1)
            {
                int l=0,u=0,d=0;
                if((inkyx-40)>=320&&maze[posinkyy][posinkyx-1]!=2&&(abs(posx-posinkyx+1)>=4||abs(posy-posinkyy)>=4))
                {
                    int a=abs(posx-(posinkyx-1));
                    int b=abs(posy-posinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if((inkyy+40)<=600&&maze[posinkyy-1][posinkyx]!=2)
                {
                    int a=abs(posx-posinkyx);
                    int b=abs(posy-(posinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((inkyy-40)>=40&&maze[posinkyy+1][posinkyx]!=2)
                {
                    int a=abs(posx-posinkyx);
                    int b=abs(posy-(posinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u==0&&l==0&&d==0)
                {
                    inkyx+=40;
                    inkyl=0;
                    inkyr=1;
                    inkyu=0;
                    inkyd=0;
                }
                else if(u>=l&&u>=d)
                {
                    inkyy+=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=1;
                    inkyd=0;
                }
                else if(l>=d&&l>=u)
                {
                    inkyx-=40;
                    inkyl=1;
                    inkyr=0;
                    inkyu=0;
                    inkyd=0;
                }
                else
                {
                    inkyy-=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=0;
                    inkyd=1;
                }
            }
            else if(inkyr==1)
            {
                int r=0,u=0,d=0;
                if((inkyx+40)<=880&&maze[posinkyy][posinkyx+1]!=2&&(abs(posx-posinkyx-1)>=4||abs(posy-posinkyy)>=4))
                {
                    int a=abs(posx-(posinkyx+1));
                    int b=abs(posy-posinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((inkyy+40)<=600&&maze[posinkyy-1][posinkyx]!=2)
                {
                    int a=abs(posx-posinkyx);
                    int b=abs(posy-(posinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((inkyy-40)>=40&&maze[posinkyy+1][posinkyx]!=2)
                {
                    int a=abs(posx-posinkyx);
                    int b=abs(posy-(posinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u==0&&r==0&&d==0)
                {
                    inkyx-=40;
                    inkyl=1;
                    inkyr=0;
                    inkyu=0;
                    inkyd=0;
                }
                else if(u>=r&&u>=d)
                {
                    inkyy+=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=1;
                    inkyd=0;
                }
                else if(d>=u&&d>=r)
                {
                    inkyy-=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=0;
                    inkyd=1;
                }
                else
                {
                    inkyx+=40;
                    inkyl=0;
                    inkyr=1;
                    inkyu=0;
                    inkyd=0;
                }
            }
            else if(inkyu==1)
            {
                int r=0,u=0,l=0;
                if((inkyx+40)<=880&&maze[posinkyy][posinkyx+1]!=2)
                {
                    int a=abs(posx-(posinkyx+1));
                    int b=abs(posy-posinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((inkyy+40)<=600&&maze[posinkyy-1][posinkyx]!=2&&(abs(posy-posinkyy+1)>=4||abs(posx-posinkyx)>=4))
                {
                    int a=abs(posx-posinkyx);
                    int b=abs(posy-(posinkyy-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((inkyx-40)>=320&&maze[posinkyy][posinkyx-1]!=2)
                {
                    int a=abs(posx-(posinkyx-1));
                    int b=abs(posy-posinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if(u==0&&r==0&&l==0)
                {
                    inkyy-=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=0;
                    inkyd=1;
                }
                else if(u>=r&&u>=l)
                {
                    inkyy+=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=1;
                    inkyd=0;
                }
                else if(l>=r&&l>=u)
                {
                    inkyx-=40;
                    inkyl=1;
                    inkyr=0;
                    inkyu=0;
                    inkyd=0;
                }
                else
                {
                    inkyx+=40;
                    inkyl=0;
                    inkyr=1;
                    inkyu=0;
                    inkyd=0;
                }
            }
            else if(inkyd==1)
            {
                int r=0,d=0,l=0;
                if((inkyx+40)<=880&&maze[posinkyy][posinkyx+1]!=2)
                {
                    int a=abs(posx-(posinkyx+1));
                    int b=abs(posy-posinkyy);
                    r=pow(a,2)+pow(b,2);
                }
                if((inkyy-40)>=40&&maze[posinkyy+1][posinkyx]!=2&&(abs(posy-posinkyy-1)>=4||abs(posx-posinkyx)>=4))
                {
                    int a=abs(posx-posinkyx);
                    int b=abs(posy-(posinkyy+1));
                    d=pow(a,2)+pow(b,2);
                }
                if((inkyx-40)>=320&&maze[posinkyy][posinkyx-1]!=2)
                {
                    int a=abs(posx-(posinkyx-1));
                    int b=abs(posy-posinkyy);
                    l=pow(a,2)+pow(b,2);
                }
                if(l==0&&d==0&&r==0)
                {
                    inkyy+=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=1;
                    inkyd=0;
                }
                else if(l>=d&&l>=r)
                {
                    inkyx-=40;
                    inkyl=1;
                    inkyr=0;
                    inkyu=0;
                    inkyd=0;
                }
                else if(d>=l&&d>=r)
                {
                    inkyy-=40;
                    inkyl=0;
                    inkyr=0;
                    inkyu=0;
                    inkyd=1;
                }
                else
                {
                    inkyx+=40;
                    inkyl=0;
                    inkyr=1;
                    inkyu=0;
                    inkyd=0;
                }
            }
        }
    }
}
void clydechange()
{
    if(gamestate==0||gamestate==1)
    {
        posclydex=(clydex-320)/40;//14
        posclydey=14-((clydey-40)/40);//0
        if(mode==0)
        {
            if(pleft==1)
            {
                targetclydex=posx-2;
                targetclydey=posy;
            }
            else if(pright==1)
            {
                targetclydex=posx+2;
                targetclydey=posy;
            }
            else if(pup==1)
            {
                targetclydex=posx;
                targetclydey=posy-2;
            }
            else
            {
                targetclydex=posx;
                targetclydey=posy+2;
            }
            if(clydel==1)
            {
                int l=400,u=400,d=400;
                if((clydex-40)>=320&&maze[posclydey][posclydex-1]!=2)
                {
                    int a=abs(targetclydex-(posclydex-1));
                    int b=abs(targetclydey-posclydey);
                    l=pow(a,2)+pow(b,2);
                }
                if((clydey+40)<=600&&maze[posclydey-1][posclydex]!=2)
                {
                    int a=abs(targetclydex-posclydex);
                    int b=abs(targetclydey-(posclydey-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((clydey-40)>=40&&maze[posclydey+1][posclydex]!=2)
                {
                    int a=abs(targetclydex-posclydex);
                    int b=abs(targetclydey-(posclydey+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u<=l&&u<=d)
                {
                    clydey+=40;
                    clydel=0;
                    clyder=0;
                    clydeu=1;
                    clyded=0;
                }
                else if(l<=d&&l<=u)
                {
                    clydex-=40;
                    clydel=1;
                    clyder=0;
                    clydeu=0;
                    clyded=0;
                }
                else
                {
                    clydey-=40;
                    clydel=0;
                    clyder=0;
                    clydeu=0;
                    clyded=1;
                }
            }
            else if(clyder==1)
            {
                int r=400,u=400,d=400;
                if((clydex+40)<=880&&maze[posclydey][posclydex+1]!=2)
                {
                    int a=abs(targetclydex-(posclydex+1));
                    int b=abs(targetclydey-posclydey);
                    r=pow(a,2)+pow(b,2);
                }
                if((clydey+40)<=600&&maze[posclydey-1][posclydex]!=2)
                {
                    int a=abs(targetclydex-posclydex);
                    int b=abs(targetclydey-(posclydey-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((clydey-40)>=40&&maze[posclydey+1][posclydex]!=2)
                {
                    int a=abs(targetclydex-posclydex);
                    int b=abs(targetclydey-(posclydey+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u<=r&&u<=d)
                {
                    clydey+=40;
                    clydel=0;
                    clyder=0;
                    clydeu=1;
                    clyded=0;
                }
                else if(d<=u&&d<=r)
                {
                    clydey-=40;
                    clydel=0;
                    clyder=0;
                    clydeu=0;
                    clyded=1;
                }
                else
                {
                    clydex+=40;
                    clydel=0;
                    clyder=1;
                    clydeu=0;
                    clyded=0;
                }
            }
            else if(clydeu==1)
            {
                int r=400,u=400,l=400;
                if((clydex+40)<=880&&maze[posclydey][posclydex+1]!=2)
                {
                    int a=abs(targetclydex-(posclydex+1));
                    int b=abs(targetclydey-posclydey);
                    r=pow(a,2)+pow(b,2);
                }
                if((clydey+40)<=600&&maze[posclydey-1][posclydex]!=2)
                {
                    int a=abs(targetclydex-posclydex);
                    int b=abs(targetclydey-(posclydey-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((clydex-40)>=320&&maze[posclydey][posclydex-1]!=2)
                {
                    int a=abs(targetclydex-(posclydex-1));
                    int b=abs(targetclydey-posclydey);
                    l=pow(a,2)+pow(b,2);
                }
                if(u<=r&&u<=l)
                {
                    clydey+=40;
                    clydel=0;
                    clyder=0;
                    clydeu=1;
                    clyded=0;
                }
                else if(l<=r&&l<=u)
                {
                    clydex-=40;
                    clydel=1;
                    clyder=0;
                    clydeu=0;
                    clyded=0;
                }
                else
                {
                    clydex+=40;
                    clydel=0;
                    clyder=1;
                    clydeu=0;
                    clyded=0;
                }
            }
            else if(clyded==1)
            {
                int r=400,d=400,l=400;
                if((clydex+40)<=880&&maze[posclydey][posclydex+1]!=2)
                {
                    int a=abs(targetclydex-(posclydex+1));
                    int b=abs(targetclydey-posclydey);
                    r=pow(a,2)+pow(b,2);
                }
                if((clydey-40)>=40&&maze[posclydey+1][posclydex]!=2)
                {
                    int a=abs(targetclydex-posclydex);
                    int b=abs(targetclydey-(posclydey+1));
                    d=pow(a,2)+pow(b,2);
                }
                if((clydex-40)>=320&&maze[posclydey][posclydex-1]!=2)
                {
                    int a=abs(targetclydex-(posclydex-1));
                    int b=abs(targetclydey-posclydey);
                    l=pow(a,2)+pow(b,2);
                }
                if(l<=d&&l<=r)
                {
                    clydex-=40;
                    clydel=1;
                    clyder=0;
                    clydeu=0;
                    clyded=0;
                }
                else if(d<=l&&d<=r)
                {
                    clydey-=40;
                    clydel=0;
                    clyder=0;
                    clydeu=0;
                    clyded=1;
                }
                else
                {
                    clydex+=40;
                    clydel=0;
                    clyder=1;
                    clydeu=0;
                    clyded=0;
                }
            }
        }
        else if(mode==1)
        {
            if(pleft==1)
            {
                targetclydex=posx-2;
                targetclydey=posy;
            }
            else if(pright==1)
            {
                targetclydex=posx+2;
                targetclydey=posy;
            }
            else if(pup==1)
            {
                targetclydex=posx;
                targetclydey=posy-2;
            }
            else
            {
                targetclydex=posx;
                targetclydey=posy+2;
            }
            if(clydel==1)
            {
                int l=0,u=0,d=0;
                if((clydex-40)>=320&&maze[posclydey][posclydex-1]!=2)
                {
                    int a=abs(targetclydex-(posclydex-1));
                    int b=abs(targetclydey-posclydey);
                    l=pow(a,2)+pow(b,2);
                }
                if((clydey+40)<=600&&maze[posclydey-1][posclydex]!=2)
                {
                    int a=abs(targetclydex-posclydex);
                    int b=abs(targetclydey-(posclydey-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((clydey-40)>=40&&maze[posclydey+1][posclydex]!=2)
                {
                    int a=abs(targetclydex-posclydex);
                    int b=abs(targetclydey-(posclydey+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u>=l&&u>=d)
                {
                    clydey+=40;
                    clydel=0;
                    clyder=0;
                    clydeu=1;
                    clyded=0;
                }
                else if(l>=d&&l>=u)
                {
                    clydex-=40;
                    clydel=1;
                    clyder=0;
                    clydeu=0;
                    clyded=0;
                }
                else
                {
                    clydey-=40;
                    clydel=0;
                    clyder=0;
                    clydeu=0;
                    clyded=1;
                }
            }
            else if(clyder==1)
            {
                int r=0,u=0,d=0;
                if((clydex+40)<=880&&maze[posclydey][posclydex+1]!=2)
                {
                    int a=abs(targetclydex-(posclydex+1));
                    int b=abs(targetclydey-posclydey);
                    r=pow(a,2)+pow(b,2);
                }
                if((clydey+40)<=600&&maze[posclydey-1][posclydex]!=2)
                {
                    int a=abs(targetclydex-posclydex);
                    int b=abs(targetclydey-(posclydey-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((clydey-40)>=40&&maze[posclydey+1][posclydex]!=2)
                {
                    int a=abs(targetclydex-posclydex);
                    int b=abs(targetclydey-(posclydey+1));
                    d=pow(a,2)+pow(b,2);
                }
                if(u>=r&&u>=d)
                {
                    clydey+=40;
                    clydel=0;
                    clyder=0;
                    clydeu=1;
                    clyded=0;
                }
                else if(d>=u&&d>=r)
                {
                    clydey-=40;
                    clydel=0;
                    clyder=0;
                    clydeu=0;
                    clyded=1;
                }
                else
                {
                    clydex+=40;
                    clydel=0;
                    clyder=1;
                    clydeu=0;
                    clyded=0;
                }
            }
            else if(clydeu==1)
            {
                int r=0,u=0,l=0;
                if((clydex+40)<=880&&maze[posclydey][posclydex+1]!=2)
                {
                    int a=abs(targetclydex-(posclydex+1));
                    int b=abs(targetclydey-posclydey);
                    r=pow(a,2)+pow(b,2);
                }
                if((clydey+40)<=600&&maze[posclydey-1][posclydex]!=2)
                {
                    int a=abs(targetclydex-posclydex);
                    int b=abs(targetclydey-(posclydey-1));
                    u=pow(a,2)+pow(b,2);
                }
                if((clydex-40)>=320&&maze[posclydey][posclydex-1]!=2)
                {
                    int a=abs(targetclydex-(posclydex-1));
                    int b=abs(targetclydey-posclydey);
                    l=pow(a,2)+pow(b,2);
                }
                if(u>=r&&u>=l)
                {
                    clydey+=40;
                    clydel=0;
                    clyder=0;
                    clydeu=1;
                    clyded=0;
                }
                else if(l>=r&&l>=u)
                {
                    clydex-=40;
                    clydel=1;
                    clyder=0;
                    clydeu=0;
                    clyded=0;
                }
                else
                {
                    clydex+=40;
                    clydel=0;
                    clyder=1;
                    clydeu=0;
                    clyded=0;
                }
            }
            else if(clyded==1)
            {
                int r=0,d=0,l=0;
                if((clydex+40)<=880&&maze[posclydey][posclydex+1]!=2)
                {
                    int a=abs(targetclydex-(posclydex+1));
                    int b=abs(targetclydey-posclydey);
                    r=pow(a,2)+pow(b,2);
                }
                if((clydey-40)>=40&&maze[posclydey+1][posclydex]!=2)
                {
                    int a=abs(targetclydex-posclydex);
                    int b=abs(targetclydey-(posclydey+1));
                    d=pow(a,2)+pow(b,2);
                }
                if((clydex-40)>=320&&maze[posclydey][posclydex-1]!=2)
                {
                    int a=abs(targetclydex-(posclydex-1));
                    int b=abs(targetclydey-posclydey);
                    l=pow(a,2)+pow(b,2);
                }
                if(l>=d&&l>=r)
                {
                    clydex-=40;
                    clydel=1;
                    clyder=0;
                    clydeu=0;
                    clyded=0;
                }
                else if(d>=l&&d>=r)
                {
                    clydey-=40;
                    clydel=0;
                    clyder=0;
                    clydeu=0;
                    clyded=1;
                }
                else
                {
                    clydex+=40;
                    clydel=0;
                    clyder=1;
                    clydeu=0;
                    clyded=0;
                }
            }
        }
    }
}
void timechange()
{
    gametime--;
    if(mode==1)
    {
        t++;
    }
}
void pacmandeath()
{
    if(mode==0)
    {
        if(posblinkyx==posx&&posblinkyy==posy)
        {
            PlaySound(0,0,0);
            PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\death.wav"),NULL,SND_ASYNC);
            pacmanlive--;
            px=600,py=320;
            posx=(px-320)/40,posy=14-((py-40)/40);
        }
        if(pospinkyx==posx&&pospinkyy==posy)
        {
            PlaySound(0,0,0);
            PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\death.wav"),NULL,SND_ASYNC);
            pacmanlive--;
            px=600,py=320;
            posx=(px-320)/40,posy=14-((py-40)/40);
        }
        if(posinkyx==posx&&posinkyy==posy)
        {
            PlaySound(0,0,0);
            PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\death.wav"),NULL,SND_ASYNC);
            pacmanlive--;
            px=600,py=320;
            posx=(px-320)/40,posy=14-((py-40)/40);
        }
        if(posclydex==posx&&posclydey==posy)
        {
            PlaySound(0,0,0);
            PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\death.wav"),NULL,SND_ASYNC);
            pacmanlive--;
            px=600,py=320;
            posx=(px-320)/40,posy=14-((py-40)/40);
        }
    }
}
void ghostdeath()
{
    if(mode==1)
    {
        if(posblinkyx==posx&&posblinkyy==posy)
        {
            PlaySound(0,0,0);
            PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\ghost.wav"),NULL,SND_ASYNC);
            blinkyl=1;
            blinkyr=0;
            blinkyu=0;
            blinkyd=0;
            blinkyx=880;
            blinkyy=600;
            score+=s;
            //Beep(500,500);
        }
        if(pospinkyx==posx&&pospinkyy==posy)
        {
            PlaySound(0,0,0);
            PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\ghost.wav"),NULL,SND_ASYNC);
            pinkyl=0;
            pinkyr=1;
            pinkyu=0;
            pinkyd=0;
            pinkyx=320;
            pinkyy=600;
            score+=s;
            //Beep(500,500);
        }
        if(posinkyx==posx&&posinkyy==posy)
        {
            PlaySound(0,0,0);
            PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\ghost.wav"),NULL,SND_ASYNC);
            inkyl=1;
            inkyr=0;
            inkyu=0;
            inkyd=0;
            inkyx=840;
            inkyy=40;
            score+=s;
            //Beep(500,500);
        }
        if(posclydex==posx&&posclydey==posy)
        {
            PlaySound(0,0,0);
            PlaySound(TEXT("C:\\Users\\ASUS\\Downloads\\ghost.wav"),NULL,SND_ASYNC);
            clydel=0;
            clyder=1;
            clydeu=0;
            clyded=0;
            clydex=360;
            clydey=40;
            score+=s;
            //Beep(500,500);
        }
    }
}
void modechange()
{
    if(mode==1&&t>5)
    {
        mode=0;
        s=0;
        t=0;
    }
}
void reload()
{
    fptr=fopen("bijoy.txt","w");
    fprintf(fptr,"%d\n",blinkyl);
    fprintf(fptr,"%d\n",blinkyr);
    fprintf(fptr,"%d\n",blinkyu);
    fprintf(fptr,"%d\n",blinkyd);
    fprintf(fptr,"%d\n",pinkyl);
    fprintf(fptr,"%d\n",pinkyr);
    fprintf(fptr,"%d\n",pinkyu);
    fprintf(fptr,"%d\n",pinkyd);
    fprintf(fptr,"%d\n",inkyl);
    fprintf(fptr,"%d\n",inkyr);
    fprintf(fptr,"%d\n",inkyu);
    fprintf(fptr,"%d\n",inkyd);
    fprintf(fptr,"%d\n",clydel);
    fprintf(fptr,"%d\n",clyder);
    fprintf(fptr,"%d\n",clydeu);
    fprintf(fptr,"%d\n",clyded);
    fprintf(fptr,"%d\n",blinkyx);
    fprintf(fptr,"%d\n",blinkyy);
    fprintf(fptr,"%d\n",pinkyx);
    fprintf(fptr,"%d\n",pinkyy);
    fprintf(fptr,"%d\n",inkyx);
    fprintf(fptr,"%d\n",inkyy);
    fprintf(fptr,"%d\n",clydex);
    fprintf(fptr,"%d\n",clydey);
    fprintf(fptr,"%d\n",px);
    fprintf(fptr,"%d\n",py);
    fprintf(fptr,"%d\n",pleft);
    fprintf(fptr,"%d\n",pright);
    fprintf(fptr,"%d\n",pup);
    fprintf(fptr,"%d\n",pdown);
    fprintf(fptr,"%d\n",ileft);
    fprintf(fptr,"%d\n",iright);
    fprintf(fptr,"%d\n",iup);
    fprintf(fptr,"%d\n",idown);
    fprintf(fptr,"%d\n",pacmanlive);
    fprintf(fptr,"%d\n",mode);
    fprintf(fptr,"%d\n",gametime);
    fprintf(fptr,"%d\n",score);
    fprintf(fptr,"%d\n",flag);
    fprintf(fptr,"%d\n",index);
    fprintf(fptr,"%d\n",ind);
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            fprintf(fptr,"%d\n",maze[i][j]);
        }
    }
    fclose(fptr);
}
void read()
{
    fptr=fopen("bijoy.txt","r");
    fscanf(fptr,"%d\n",&blinkyl);
    fscanf(fptr,"%d\n",&blinkyr);
    fscanf(fptr,"%d\n",&blinkyu);
    fscanf(fptr,"%d\n",&blinkyd);
    fscanf(fptr,"%d\n",&pinkyl);
    fscanf(fptr,"%d\n",&pinkyr);
    fscanf(fptr,"%d\n",&pinkyu);
    fscanf(fptr,"%d\n",&pinkyd);
    fscanf(fptr,"%d\n",&inkyl);
    fscanf(fptr,"%d\n",&inkyr);
    fscanf(fptr,"%d\n",&inkyu);
    fscanf(fptr,"%d\n",&inkyd);
    fscanf(fptr,"%d\n",&clydel);
    fscanf(fptr,"%d\n",&clyder);
    fscanf(fptr,"%d\n",&clydeu);
    fscanf(fptr,"%d\n",&clyded);
    fscanf(fptr,"%d\n",&blinkyx);
    fscanf(fptr,"%d\n",&blinkyy);
    fscanf(fptr,"%d\n",&pinkyx);
    fscanf(fptr,"%d\n",&pinkyy);
    fscanf(fptr,"%d\n",&inkyx);
    fscanf(fptr,"%d\n",&inkyy);
    fscanf(fptr,"%d\n",&clydex);
    fscanf(fptr,"%d\n",&clydey);
    fscanf(fptr,"%d\n",&px);
    fscanf(fptr,"%d\n",&py);
    fscanf(fptr,"%d\n",&pleft);
    fscanf(fptr,"%d\n",&pright);
    fscanf(fptr,"%d\n",&pup);
    fscanf(fptr,"%d\n",&pdown);
    fscanf(fptr,"%d\n",&ileft);
    fscanf(fptr,"%d\n",&iright);
    fscanf(fptr,"%d\n",&iup);
    fscanf(fptr,"%d\n",&idown);
    fscanf(fptr,"%d\n",&pacmanlive);
    fscanf(fptr,"%d\n",&mode);
    fscanf(fptr,"%d\n",&gametime);
    fscanf(fptr,"%d\n",&score);
    fscanf(fptr,"%d\n",&flag);
    fscanf(fptr,"%d\n",&index);
    fscanf(fptr,"%d\n",&ind);
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            fscanf(fptr,"%d\n",&maze[i][j]);
        }
    }
    fclose(fptr);
}
int main()
{
    iSetTimer(20,reload);
    if(gamestate==(-1))
    {
        FILE *f;
        f=fopen("saeem.txt","r");
        if ((f= fopen("saeem.txt", "r")) != NULL)
        {
            while(EOF!=fscanf(f,"%d",&highscore[ind].score))
            {
                fscanf(f,"%[]",highscore[ind].score);
                fscanf(f,"%[^\n]",highscore[ind].name);
                ind++;
            }
        }
    }
    iSetTimer(20,modechange);
    iSetTimer(20,pacmandeath);
    iSetTimer(20,ghostdeath);
    iSetTimer(100,pacmanchange);
    iSetTimer(300,blinkychange);
    iSetTimer(300,pinkychange);
    iSetTimer(300,inkychange);
    iSetTimer(300,clydechange);
    iSetTimer(1000,timechange);
    int sum=50;
    for(int i=4; i>=0; i--)
    {
        bcordinate[i].x=50;
        bcordinate[i].y=sum;
        sum+=150;
    }
        PlaySound(TEXT("C:\\Users\\ASUS\\Music\\song.wav"),NULL,SND_LOOP|SND_ASYNC);
    iInitialize(screenwidth, screenheight, "Pacman!");
    return 0;
}




