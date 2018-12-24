#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <cmath>
#include <queue>
#include <iomanip>

#define POZYCJA_X 0
#define POZYCJA_Y 1
#define KRAWEDZ 2
#define SCIEZKA 3
#include <iostream>
#define ILOSC_WIERZCHOLKOW 150
#define Ds 100
#define PROMIEN 5.0

#define OKNO_X 865
#define OKNO_Y 579

#define SKALA 0.248329621380

#define ROZMIAR_X 865
#define ROZMIAR_Y 579

using namespace std;

typedef uint8_t **Mapa;

  struct PUNKT{
unsigned int x,y;
PUNKT() {x=y=0;}
PUNKT(unsigned int a, unsigned int b){
x=a;
y=b;
}
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(OKNO_X, OKNO_Y), "SFML window");
    window.setVerticalSyncEnabled(true);
    sf::Texture mapa;
    sf::Texture mapa2;
    mapa.setRepeated(true);
    sf::Texture kwadratTexture;
    sf::Texture mapaGotowa;
    sf::Texture krawedzie;
    sf::Image obraz;
    sf::Image kwadrat;
    sf::Image biale;
    sf::Sprite sprite;
    sf::Sprite sprite2;
    sf::Color kolor;
    sf::CircleShape shape(PROMIEN);
    shape.setOrigin(PROMIEN,PROMIEN);
    int ilosc_wierzcholkow = 300;
    int pozycjaX;
    int pozycjaY;
    int x,y;
    bool odwiedzone[ilosc_wierzcholkow+2];
    srand (time(NULL));
    sf::IntRect r1(0, 0, 2*ROZMIAR_X, ROZMIAR_Y);
    //unsigned int maximum = sf::Texture::getMaximumSize();
    if (!mapa.loadFromFile("mapa1.png"))
    {
        return 1;
        // error...
    }
    if (!mapa2.loadFromFile("biale.png"))
    {
        return 1;
        // error...
    }
    if (!kwadratTexture.loadFromFile("kwadrat.png"))
    {
        return 1;
        // error...
    }
    kwadrat = kwadratTexture.copyToImage();
    biale = mapa2.copyToImage();
    sf::Color alfa;
    alfa = biale.getPixel(1,1);

    alfa.a = 0;
    for(int i = 0; i<ROZMIAR_X; i++)
    {
        for(int j = 0; j<ROZMIAR_Y; j++)
        {
            biale.setPixel(i,j,alfa);
        }
    }
    //alfa = biale.getPixel(1,1);

    //alfa = sf::Color::Cyan;


///////////// 1D /////////////////

///////////// 2D /////////////////


// ZAPISYWANIE POZYCJI PIERWSZEGO I OSTATNIEGO PUNKTU

   // double graf[ilosc_wierzcholkow+2][ilosc_wierzcholkow+2][4];

double*** graf=new double**[865];
for(int i = 0; i<=865;i++)
{
   graf[i]=new double*[579];

   for (int j=0; j<=579;j++)
    graf[i][j]= new double[4];
}




    graf[0][0][POZYCJA_X]=791;
    graf[0][0][POZYCJA_Y]=195;
    graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_X]=434;
    graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_Y]=156;
    obraz = mapa.copyToImage();
    sprite.setTexture(mapa);
    //sprite.setTextureRect();
    window.draw(sprite);
int odleglosc;
    shape.setFillColor(sf::Color::Yellow);
    bool byloCzarne;
    bool byloBiale;
    int metoda=1;
    if (metoda==2)
        odleglosc = 200;
    if (metoda==1)
        odleglosc=400;
    if(metoda==0)
        odleglosc=200;

  if(metoda==1){

      int** mapa = new int*[865];
  for (int i=0;i<=865;i++)
    mapa[i]=new int[579];



 for (int i=0;i<=865;i++){
     for (int j=0;j<=579;j++){
            if((obraz.getPixel(i,j).r <200)&&(obraz.getPixel(i,j).g <200)&&(obraz.getPixel(i,j).b <200))
                        {
                        mapa[i][j]=1;
                    }
                    else{

                    mapa[i][j]=0;

shape.setPosition(i,j);
            window.draw(shape);


         }


     }}

     int** wyniki = new int*[865];
  for (int i=0;i<=865;i++)
    wyniki[i]=new int[579];

    for (int i=0;i<=865;i++){
     for (int j=0;j<=579;j++){
            wyniki[i][j]=0;
     }}
//djikstra dla metody rastowej
queue <PUNKT> rdoprzetworzenia;
queue <PUNKT> rprzetworzone;
PUNKT koncowy;
PUNKT startowy;
startowy.x=791;
startowy.y=195;

koncowy.x=434;
koncowy.y=156;

cout<<mapa[startowy.x][startowy.y];
cout<<mapa[koncowy.x][koncowy.y];

rdoprzetworzenia.push(startowy);
while(rdoprzetworzenia.empty()==false){
    PUNKT przetwarzany = rdoprzetworzenia.front();
    //cout<<"przetwarzany = "<<przetwarzany.x<<" "<<przetwarzany.y<<endl;
    if(przetwarzany.x==koncowy.x&&przetwarzany.y==koncowy.y){
          cout<<"znalazlo2";
        break;} //dotarlismy do celu
        if(przetwarzany.x>0){
            PUNKT kolejny(przetwarzany.x-1,przetwarzany.y);
            if(mapa[kolejny.x][kolejny.y]==1){}
            if(mapa[kolejny.x][kolejny.y]==0){

                wyniki[kolejny.x][kolejny.y]=wyniki[przetwarzany.x][przetwarzany.y]+1;

                mapa[kolejny.x][kolejny.y]=2;
                rdoprzetworzenia.push(kolejny);



            }if(mapa[kolejny.x][kolejny.y]==2){
        //        cout<<"znalazlo odwiedzony"<<endl;
                if(wyniki[kolejny.x][kolejny.y]>wyniki[przetwarzany.x][przetwarzany.y]+1){
          //              cout<<"krotsza sciezka"<<endl;
                    wyniki[kolejny.x][kolejny.y]=wyniki[przetwarzany.x][przetwarzany.y]+1;
                    rdoprzetworzenia.push(kolejny);



                }
            }


        }
        if(przetwarzany.y>0){
            PUNKT kolejny(przetwarzany.x,przetwarzany.y-1);
            if(mapa[kolejny.x][kolejny.y]==1){}
            if(mapa[kolejny.x][kolejny.y]==0){
                 wyniki[kolejny.x][kolejny.y]=wyniki[przetwarzany.x][przetwarzany.y]+1;

                mapa[kolejny.x][kolejny.y]=2;
                rdoprzetworzenia.push(kolejny);



        }
        if(mapa[kolejny.x][kolejny.y]==2){
            //cout<<"znalazlo odwiedzony"<<endl;

                if(wyniki[kolejny.x][kolejny.y]>wyniki[przetwarzany.x][przetwarzany.y]+1){
              //          cout<<"krotsza sciezka"<<endl;
                    wyniki[kolejny.x][kolejny.y]=wyniki[przetwarzany.x][przetwarzany.y]+1;
                    rdoprzetworzenia.push(kolejny);



                }
            }
        }
        if(przetwarzany.x<864){
            PUNKT kolejny(przetwarzany.x+1,przetwarzany.y);
            if(mapa[kolejny.x][kolejny.y]==1){}
            if(mapa[kolejny.x][kolejny.y]==0){
                 wyniki[kolejny.x][kolejny.y]=wyniki[przetwarzany.x][przetwarzany.y]+1;

                mapa[kolejny.x][kolejny.y]=2;
                rdoprzetworzenia.push(kolejny);

            if(mapa[kolejny.x][kolejny.y]==2){
                //    cout<<"znalazlo odwiedzony"<<endl;
                if(wyniki[kolejny.x][kolejny.y]>wyniki[przetwarzany.x][przetwarzany.y]+1){
                  // cout<<"krotsza sciezka"<<endl;
                   //cin.get();
                    wyniki[kolejny.x][kolejny.y]=wyniki[przetwarzany.x][przetwarzany.y]+1;
                    rdoprzetworzenia.push(kolejny);



                }
            }
        }
        }
        if(przetwarzany.y<579){
            PUNKT kolejny(przetwarzany.x,przetwarzany.y+1);
            if(mapa[kolejny.x][kolejny.y]==1){}
            if(mapa[kolejny.x][kolejny.y]==0){
                 wyniki[kolejny.x][kolejny.y]=wyniki[przetwarzany.x][przetwarzany.y]+1;

                mapa[kolejny.x][kolejny.y]=2;
                rdoprzetworzenia.push(kolejny);



        }if(mapa[kolejny.x][kolejny.y]==2){

                if(wyniki[kolejny.x][kolejny.y]>wyniki[przetwarzany.x][przetwarzany.y]+1){
                     //   cout<<"krotsza sciezka"<<endl;
                    wyniki[kolejny.x][kolejny.y]=wyniki[przetwarzany.x][przetwarzany.y]+1;
                    rdoprzetworzenia.push(kolejny);


                }
            }
}

rdoprzetworzenia.pop();
}




    rprzetworzone.push(koncowy);
    cout<<"pchnieto koncowy";

cout<<"start1="<< wyniki[startowy.x][startowy.y]<<endl;
cout<<"koniec1="<< wyniki[koncowy.x][koncowy.y]<<endl;
while(rprzetworzone.empty()==false)
{
    PUNKT przetwarzany=rprzetworzone.front();
    if(przetwarzany.x==startowy.x&&przetwarzany.y==startowy.y||przetwarzany.x==startowy.x+1&&przetwarzany.y==startowy.y
       ||przetwarzany.x==startowy.x&&przetwarzany.y==startowy.y+1||przetwarzany.x==startowy.x-1&&przetwarzany.y==startowy.y
       ||przetwarzany.x==startowy.x&&przetwarzany.y==startowy.y-1){
        cout<<"znalazlo1";
        break;}


        obraz.setPixel((unsigned int)przetwarzany.x,(unsigned int)(przetwarzany.y),sf::Color::Cyan);
        biale.setPixel((unsigned int)przetwarzany.x,(unsigned int)(przetwarzany.y),sf::Color::Cyan);

     //dotarlismy do celu
        if(przetwarzany.x>0){
            PUNKT kolejny;
           kolejny.x= przetwarzany.x-1;
           kolejny.y=przetwarzany.y;

            if(wyniki[kolejny.x][kolejny.y]+1==wyniki[przetwarzany.x][przetwarzany.y]){
                   // cout<<"kolejny1="<< wyniki[kolejny.x][kolejny.y];
                    //cout<<"przetwarzany1="<< wyniki[przetwarzany.x][przetwarzany.y]<<endl;

                rprzetworzone.push(kolejny);
                rprzetworzone.pop();
                continue;
            }
        }
        if(przetwarzany.y>0){
            PUNKT kolejny;
           kolejny.x= przetwarzany.x;
        kolejny.y=przetwarzany.y-1;

            if(wyniki[kolejny.x][kolejny.y]+1==wyniki[przetwarzany.x][przetwarzany.y]){
                    //cout<<"kolejny2="<< wyniki[kolejny.x][kolejny.y];
                    //cout<<"przetwarzany2="<< wyniki[przetwarzany.x][przetwarzany.y]<<endl;
           //         obraz.setPixel((unsigned int)kolejny.x,(unsigned int)(kolejny.y),sf::Color::Cyan);
          //    biale.setPixel((unsigned int)kolejny.x,(unsigned int)(kolejny.y),sf::Color::Cyan);
                rprzetworzone.push(kolejny);
                rprzetworzone.pop();
                continue;
            }
        }
        if(przetwarzany.x<865){
            PUNKT kolejny;
           kolejny.x= przetwarzany.x+1;
        kolejny.y=przetwarzany.y;

            if(wyniki[kolejny.x][kolejny.y]==wyniki[przetwarzany.x][przetwarzany.y]-1){
                    //cout<<"kolejny3="<< wyniki[kolejny.x][kolejny.y];
                    //cout<<"przetwarzany3="<< wyniki[przetwarzany.x][przetwarzany.y]<<endl;
           //         obraz.setPixel((unsigned int)kolejny.x,(unsigned int)(kolejny.y),sf::Color::Cyan);
             //   biale.setPixel((unsigned int)kolejny.x,(unsigned int)(kolejny.y),sf::Color::Cyan);
                rprzetworzone.push(kolejny);
                rprzetworzone.pop();
                continue;
            }
        }
        if(przetwarzany.y<579){
            PUNKT kolejny;
           kolejny.x= przetwarzany.x;
           kolejny.y=przetwarzany.y+1;

            if(wyniki[kolejny.x][kolejny.y]==wyniki[przetwarzany.x][przetwarzany.y]-1){
                  //cout<<"kolejny4="<< wyniki[kolejny.x][kolejny.y];
                    //cout<<"przetwarzany4="<< wyniki[przetwarzany.x][przetwarzany.y]<<endl;
                    obraz.setPixel((unsigned int)kolejny.x,(unsigned int)(kolejny.y),sf::Color::Cyan);
                biale.setPixel((unsigned int)kolejny.x,(unsigned int)(kolejny.y),sf::Color::Cyan);
                rprzetworzone.push(kolejny);
                rprzetworzone.pop();
                continue;
            }
        }









}
cout<<endl;
for(int j=koncowy.y;j<=koncowy.y+40;j++){
    for(int i=koncowy.x-40;i<=koncowy.x;i++)
    cout<<setw(4)<<wyniki[i][j];
    cout<<"\n";
}




cout<<"znalazlo";
for(int i=0;i<=865;i++)
    {
        delete[] mapa[i];

    }
    delete[] mapa;


for(int i=0;i<=865;i++)
    {
        delete[] wyniki[i];

    }
    delete[] wyniki;
  }





/*
    graf[1][1][0]=830;
    graf[1][1][1]=480;
    pozycjaX=graf[1][1][0];
    pozycjaY=graf[1][1][1];
    shape.setPosition(pozycjaX,pozycjaY);
            window.draw(shape);
    graf[2][2][0]=50;
    graf[2][2][1]=490;
    pozycjaX=graf[2][2][0];
    pozycjaY=graf[2][2][1];
    shape.setPosition(pozycjaX,pozycjaY);
            window.draw(shape);


*/
if(metoda==2){

int kratka=1;
        int kratkaX=1;
        int kratkaY=1;
    while(kratkaX*20<=860&&kratkaY*20<=530)
    {
        byloCzarne = false;

        for(int i=1+(kratkaX-1)*20; i<=20*kratkaX;i++){

        for(int j=1+(kratkaY-1)*20; j<=20*kratkaY;j++){
           pozycjaX=i;
           pozycjaY=j;


                if((obraz.getPixel(pozycjaX,pozycjaY).r <200)&&(obraz.getPixel(pozycjaX,pozycjaY).g <200)&&(obraz.getPixel(pozycjaX,pozycjaY).b <200)){
                    byloCzarne=true;}}}
//PIERWSZY KWADRAT}
                    if(byloCzarne==true){
                            cout<<"wchodzimy"<<endl;

                    byloCzarne=false;
                    for(int i=1+(kratkaX-1)*20; i<=20*kratkaX-10;i++){
                    for(int j=1+(kratkaY-1)*20; j<=20*kratkaY-10;j++){
                    pozycjaX=i;
                    pozycjaY=j;
                     if((obraz.getPixel(pozycjaX,pozycjaY).r <200)&&(obraz.getPixel(pozycjaX,pozycjaY).g <200)&&(obraz.getPixel(pozycjaX,pozycjaY).b <200)){
                    byloCzarne=true;}
                    }}
                    if(byloCzarne==false)
                    {cout<<"wchodzimy2"<<endl;

                        graf[kratka][kratka][POZYCJA_X] = 20*(kratkaX-1)+5;
                        graf[kratka][kratka][POZYCJA_Y] = 20*(kratkaY-1)+5;
                        cout<<graf[kratka][kratka][POZYCJA_X] <<" "<<graf[kratka][kratka][POZYCJA_Y] ;
cin.get();
           // cout<<"wierzcholekX="<<graf[wierzcholek+1][wierzcholek+1][POZYCJA_X]<<"wierzcholekY="<<graf[wierzcholek+1][wierzcholek+1][POZYCJA_Y]<<endl;
            shape.setPosition(graf[kratka][kratka][POZYCJA_X],graf[kratka][kratka][POZYCJA_Y]);
            window.draw(shape);
            kratka++;
                    }



                  //DRUGI KWADRAT

                    byloCzarne=false;
                    for(int i=1+(kratkaX-1)*20+10; i<=20*kratkaX;i++){
                    for(int j=1+(kratkaY-1)*20; j<=20*kratkaY-10;j++){
                    pozycjaX=i;
                    pozycjaY=j;
                      if((obraz.getPixel(pozycjaX,pozycjaY).r <200)&&(obraz.getPixel(pozycjaX,pozycjaY).g <200)&&(obraz.getPixel(pozycjaX,pozycjaY).b <200)){
                    byloCzarne=true;}


                    }}
                    if(byloCzarne==false)
                    {
                        graf[kratka][kratka][POZYCJA_X] = 20*(kratkaX-1)+15;
                        graf[kratka][kratka][POZYCJA_Y] = 20*(kratkaY-1)+5;
           // cout<<"wierzcholekX="<<graf[wierzcholek+1][wierzcholek+1][POZYCJA_X]<<"wierzcholekY="<<graf[wierzcholek+1][wierzcholek+1][POZYCJA_Y]<<endl;
            shape.setPosition(graf[kratka][kratka][POZYCJA_X],graf[kratka][kratka][POZYCJA_Y]);
            window.draw(shape);
            kratka++;
            if(kratka==250)
                break;
                    }
//TRZECI KWADRAT

                    byloCzarne=false;
                    for(int i=1+(kratkaX-1)*20; i<=20*kratkaX-10;i++){
                    for(int j=1+(kratkaY-1)*20+10; j<=20*kratkaY;j++){
                    pozycjaX=i;
                    pozycjaY=j;
                      if((obraz.getPixel(pozycjaX,pozycjaY).r <200)&&(obraz.getPixel(pozycjaX,pozycjaY).g <200)&&(obraz.getPixel(pozycjaX,pozycjaY).b <200)){
                    byloCzarne=true;}


                    }}
                    if(byloCzarne==false)
                    {
                        graf[kratka][kratka][POZYCJA_X] = 20*(kratkaX-1)+5;
                        graf[kratka][kratka][POZYCJA_Y] = 20*(kratkaY-1)+15;
           // cout<<"wierzcholekX="<<graf[wierzcholek+1][wierzcholek+1][POZYCJA_X]<<"wierzcholekY="<<graf[wierzcholek+1][wierzcholek+1][POZYCJA_Y]<<endl;
            shape.setPosition(graf[kratka][kratka][POZYCJA_X],graf[kratka][kratka][POZYCJA_Y]);
            window.draw(shape);
            kratka++;
            if(kratka==250)
                break;
                    }

//CZWARTY KWADRAT
                    byloCzarne=false;
                    for(int i=1+(kratkaX-1)*20+10; i<=20*kratkaX;i++){
                    for(int j=1+(kratkaY-1)*20+10; j<=20*kratkaY;j++){
                    pozycjaX=i;
                    pozycjaY=j;
                      if((obraz.getPixel(pozycjaX,pozycjaY).r <200)&&(obraz.getPixel(pozycjaX,pozycjaY).g <200)&&(obraz.getPixel(pozycjaX,pozycjaY).b <200)){
                    byloCzarne=true;}


                    }}
                    if(byloCzarne==false)
                    {
                        graf[kratka][kratka][POZYCJA_X] = 20*(kratkaX-1)+15;
                        graf[kratka][kratka][POZYCJA_Y] = 20*(kratkaY-1)+15;
           // cout<<"wierzcholekX="<<graf[wierzcholek+1][wierzcholek+1][POZYCJA_X]<<"wierzcholekY="<<graf[wierzcholek+1][wierzcholek+1][POZYCJA_Y]<<endl;
            shape.setPosition(graf[kratka][kratka][POZYCJA_X],graf[kratka][kratka][POZYCJA_Y]);
            window.draw(shape);
            kratka++;
            if(kratka==250)
                break;
                    }




            }








if(byloCzarne==false){

            graf[kratka][kratka][POZYCJA_X] = 20*kratkaX-10;
            graf[kratka][kratka][POZYCJA_Y] = 20*kratkaY-10;
           // cout<<"wierzcholekX="<<graf[wierzcholek+1][wierzcholek+1][POZYCJA_X]<<"wierzcholekY="<<graf[wierzcholek+1][wierzcholek+1][POZYCJA_Y]<<endl;
            shape.setPosition(graf[kratka][kratka][POZYCJA_X],graf[kratka][kratka][POZYCJA_Y]);
            window.draw(shape);
kratka++;
if(kratka==250)
                break;
kratkaX+=4;


//cout<<"kratka"<<kratka<<endl;

}

if (kratkaX==43&&kratkaY==27)
    break;
if(kratkaX<43){
kratkaX++;
//cout<<"kratkaX"<<kratkaX<<endl;
}
else{
    kratkaX=1;
if (kratkaY<27)
    kratkaY++;
 //   cout<<"kratkay"<<kratkaY;
}


    }
ilosc_wierzcholkow=kratka;
    graf[0][0][POZYCJA_X]=791;
    graf[0][0][POZYCJA_Y]=195;
    graf[kratka+1][kratka+1][POZYCJA_X]=434;
    graf[kratka+1][kratka+1][POZYCJA_Y]=156;
    cout<<kratka;
    cin.get();

}
for(int i =0; i<ilosc_wierzcholkow+2;i++)
{
    cout<<i<<" "<<graf[i][i][0]<<" "<<graf[i][i][1]<<endl;
    cin.get();
}
















if(metoda==0){


    for(int wierzcholek=0; wierzcholek<ilosc_wierzcholkow; wierzcholek++)
    {
        byloCzarne = false;
        pozycjaX=rand()%ROZMIAR_X;
        pozycjaY=rand()%ROZMIAR_Y;
        for(int i=0; i<1; i++) // SPRAWDZANIE CZY NIE TRAFILIŚMY NA LĄD
        {
            if((pozycjaX > i)&&(pozycjaX + i < OKNO_X)&&(pozycjaY > i)&&(pozycjaY + i < OKNO_Y))
            {
                if((obraz.getPixel(pozycjaX+i,pozycjaY+i).r <200)&&(obraz.getPixel(pozycjaX+i,pozycjaY+i).g <200)&&(obraz.getPixel(pozycjaX+i,pozycjaY+i).b <200))
                    byloCzarne =true;
                if((obraz.getPixel(pozycjaX-i,pozycjaY-i).r <200)&&(obraz.getPixel(pozycjaX-i,pozycjaY-i).g <200)&&(obraz.getPixel(pozycjaX-i,pozycjaY-i).b <200))
                    byloCzarne =true;
            }
        }
        if(byloCzarne)
        {
            wierzcholek--;
        }
        else// TWORZENIE WIERZCHOŁKÓW GRAFU I ZAPISYWANIE ICH POZYCJI
        {
            graf[wierzcholek+1][wierzcholek+1][POZYCJA_X] = pozycjaX;
            graf[wierzcholek+1][wierzcholek+1][POZYCJA_Y] = pozycjaY;
            shape.setPosition(pozycjaX,pozycjaY);
            window.draw(shape);
        }
    }
}



if(metoda==1){
graf[791][195][POZYCJA_X]=791;
graf[791][195][POZYCJA_Y]=195;
graf[434][156][POZYCJA_X]=434;
graf[434][156][POZYCJA_Y]=156;
shape.setFillColor(sf::Color::Green);
shape.setPosition(791,195);
window.draw(shape);
shape.setFillColor(sf::Color::Red);
shape.setPosition(434,156);
window.draw(shape);
}





  if(metoda!=1){  //RYSOWANIE PIERWSZEGO I OSTATNIEGO WĘZŁA
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(graf[0][0][POZYCJA_X], graf[0][0][POZYCJA_Y]);
    window.draw(shape);

    shape.setFillColor(sf::Color::Red);
    shape.setPosition(graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_X],graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_Y]);
    window.draw(shape);
}
    // ZEROWANIE KRAWĘDZI GRAFU
//if(metoda!=1){
    for(int wierzcholek = 0; wierzcholek<ilosc_wierzcholkow+2; wierzcholek++)
    {
        for(int wierzcholek2 = 0; wierzcholek2<ilosc_wierzcholkow+2; wierzcholek2++)
        {
            graf[wierzcholek][wierzcholek2][KRAWEDZ]=0;
            graf[wierzcholek][wierzcholek2][SCIEZKA]=0;
        }
    }
//}


if(metoda!=1){

    //SPRAWDZANIE CZY MOŻNA UTWORZYĆ KRAWĘDŹ I TWORZENIE ICH
    for(int wierzcholek = 0; wierzcholek<ilosc_wierzcholkow+2; wierzcholek++)
    {
        for(int wierzcholek2 = wierzcholek; wierzcholek2<ilosc_wierzcholkow+2; wierzcholek2++)
        {
            if(wierzcholek == wierzcholek2)
                continue;
            byloCzarne = false;
            //double dystansX = abs((int)(graf[wierzcholek][wierzcholek][POZYCJA_X]-graf[wierzcholek2][wierzcholek2][POZYCJA_X]));
            //double dystansY = abs((int)(graf[wierzcholek][wierzcholek][POZYCJA_Y]-graf[wierzcholek2][wierzcholek2][POZYCJA_Y]));
            double dystansX = (graf[wierzcholek][wierzcholek][POZYCJA_X]-graf[wierzcholek2][wierzcholek2][POZYCJA_X]);
            double dystansY = (graf[wierzcholek][wierzcholek][POZYCJA_Y]-graf[wierzcholek2][wierzcholek2][POZYCJA_Y]);
            double dystansXY = sqrt(dystansX*dystansX+dystansY*dystansY);
            double a=dystansY/dystansX;
            double przesuniecie=0;

            if((dystansY<0)&&(dystansX<0))
                a = a;
            if((dystansY<0)&&(dystansX>0))
                a = -a;
            if((dystansY>0)&&(dystansX<0))
                a = -a;
            if((dystansY>0)&&(dystansX>0))
                a = a;
            int znakX = -1;
            if(dystansX<0)
                znakX = 1;
            int znakY = -1;
            if(dystansY<0)
                znakY = 1;
            if(dystansXY<400)
            {
if(dystansX==0)   {}

if(dystansX!=0){
                for(int i=0; i<abs((int)dystansX); i++)
                {
                    x = graf[wierzcholek][wierzcholek][POZYCJA_X]+i*znakX;
if(a!=0){
                    for(int j=0; j<ceil(abs(a)); j++)
                    {

                        y = a*i*znakY+graf[wierzcholek][wierzcholek][POZYCJA_Y]+j;


                        if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                        {
                            if((obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).r <200)&&(obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).g <200)&&(obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).b <200)){
                                byloCzarne = true;
                                if(wierzcholek==43&&wierzcholek2==42){
                                        cout<<"czarne"<<endl;
                                    cin.get();
                                }}
                        }
                    }
                }
                if(dystansY==0){
                    for(int j=0; j<dystansXY; j++)
                    {
                        {
                    }
                        y = graf[wierzcholek][wierzcholek][POZYCJA_Y];


                        if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                        {
                            if((obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).r <200)&&(obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).g <200)&&(obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).b <200))
                                byloCzarne = true;

                        }
                    }
                }
                }
                if(byloCzarne)
                    continue;

                graf[wierzcholek][wierzcholek2][KRAWEDZ]=dystansXY;

                if(wierzcholek==42&&wierzcholek2==43){
                                    cout<<"ustawiono krawedz2="<<graf[wierzcholek][wierzcholek2][KRAWEDZ] <<endl;
                                    cin.get();
                }
                for(int i=0; i<abs((int)dystansX); i++)
                {
                    x = graf[wierzcholek][wierzcholek][POZYCJA_X]+i*znakX;
                    if(a!=0){
                    for(int j=0; j<abs(a); j++)
                    {
                        //y = j*znakY+i*abs((int)a);
                        //y += graf[wierzcholek][wierzcholek][POZYCJA_X];
                        y = a*i*znakY+graf[wierzcholek][wierzcholek][POZYCJA_Y]+j;

                        if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                        {

                            obraz.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Cyan);
                            biale.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Cyan);
                        }
                    }

                    }
                    if(a==0){
                    for(int j=0; j<1; j++)
                    {
                        //y = j*znakY+i*abs((int)a);
                        //y += graf[wierzcholek][wierzcholek][POZYCJA_X];
                        y = graf[wierzcholek][wierzcholek][POZYCJA_Y];
                        if(wierzcholek==42&&wierzcholek2==43)
cout<<x<<" sprawdz "<<y<<endl;
                        if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                        {

                            obraz.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Cyan);
                            biale.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Cyan);
                        }
                    }

                    }



                    }
            }
                    }
                    if(dystansXY>600)
            {
                if(dystansX>0){
                dystansX = 865 - dystansX;

                }
              if(dystansX<0){
                dystansX = 865 + dystansX;

                }




              dystansXY = sqrt(dystansX*dystansX+dystansY*dystansY);


 if(dystansY<0)
    dystansY=-dystansY;
    a=dystansY/dystansX;
                for(int i=0; i<abs((int)dystansX); i++)
                {
                    x = graf[wierzcholek][wierzcholek][POZYCJA_X]-i*znakX+przesuniecie;

                    if(x>865){
                        przesuniecie= -865;

                }
                    if(x<0){
                        przesuniecie=+865;
}

if(a!=0){
                    for(int j=0; j<ceil(abs(a)); j++)
                    {
                        y = a*i*znakY+graf[wierzcholek][wierzcholek][POZYCJA_Y]+j;

                        if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                        {
                            if((obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).r <200)&&(obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).g <200)&&(obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).b <200))
                               {

                                byloCzarne = true;

                               }

                        }
                    }
}
if(a==0){
                    for(int j=0; j<1; j++)
                    {
                        y = graf[wierzcholek][wierzcholek][POZYCJA_Y];

                        if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                        {
                            if((obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).r <200)&&(obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).g <200)&&(obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).b <200))
                               {

                                byloCzarne = true;

                               }

                        }
                    }
}
                }

                if(byloCzarne)
                    continue;
                graf[wierzcholek][wierzcholek2][KRAWEDZ]=dystansXY;
                przesuniecie=0;
                for(int i=0; i<abs((int)dystansX); i++)
                {
                    x = graf[wierzcholek][wierzcholek][POZYCJA_X]-i*znakX+przesuniecie;
                    if(x>864){
                        przesuniecie= -864;

                        }
                    if(x<1){
                        przesuniecie= +864;}

                    for(double j=0; j<ceil(abs(a)); j++)
                    {
                        //y = j*zprzenakY+i*abs((int)a);
                        //y += graf[wierzcholek][wierzcholek][POZYCJA_X];
                        y = a*i*znakY+graf[wierzcholek][wierzcholek][POZYCJA_Y]+j;

                        if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                        {

                            obraz.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Cyan);
                            biale.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Cyan);
                        }
                    }


                    /*for(int j=0; j<abs((int)a); j++)
                    {
                    y = ceil(i*abs(a))*znakY+j*znakY+graf[wierzcholek][wierzcholek][POZYCJA_Y];
                    //y = graf[wierzcholek][wierzcholek][POZYCJA_Y]+j*znakY;
                    //y=j*znakY+i*j*znakY+graf[wierzcholek][wierzcholek][POZYCJA_Y];
                    if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                    {
                        obraz.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Cyan);
                    }
                    }*/
                }//sf::Vertex line[] = {{{graf[wierzcholek][wierzcholek][POZYCJA_X], graf[wierzcholek][wierzcholek][POZYCJA_Y]}, sf::Color::Cyan}, {{graf[wierzcholek2][wierzcholek2][POZYCJA_X], graf[wierzcholek2][wierzcholek2][POZYCJA_Y]}, sf::Color::Cyan}};
            }//window.draw(line, sf::Lines);
            //
        }
    }

}

for(int i =0; i<ilosc_wierzcholkow+2;i++)
{
    for(int j =0; j<ilosc_wierzcholkow+2;j++)
graf[j][i][2]=graf[i][j][2];

cout<<i<<" "<<graf[251][i][2]<<" "<<graf[i][251][2]<<endl;
    cin.get();
}


//algorytm djikstry
/*

   int b=0;
	int n = ilosc_wierzcholkow+2;
	int p[n];
	double d[n];
	d[0]=0;
	p[0]=-1;

	int pkt=0;
	int licznik=0;
	int poprzednie;




	int t=0;
	int z=0;
	int punkt_sciezki[Ds];


	int poczatek;
	double wynik;

	//ustawianie tablic

	for(int x = 1; x<ilosc_wierzcholkow+2;x++)
	{
		p[x]=-1;
		d[x]=9999;
		//cout<<p[x]<<" ";
	}

queue <int> kolejkaDoPrzetworzenia;
queue <int> kolejkaPrzetworzona;

kolejkaDoPrzetworzenia.push(0);
int licznik2=0;
while (kolejkaDoPrzetworzenia.empty()==false){
       // cout<<"szuka";
if (licznik2==100000000){
        cout<<"zjebalo sie";
    break;
    }
int numer= kolejkaDoPrzetworzenia.front();
odwiedzone[numer]=true;
cout<<"odwiedzono"<<numer<<endl;

//cout<<"numer="<<numer<<" "<<graf[numer][numer][0]<<" "<<graf[numer][numer][1]<<endl;

if (numer == ilosc_wierzcholkow+1){
        kolejkaPrzetworzona.push(numer);
				kolejkaDoPrzetworzenia.pop();
    break;
}
for(int j=0;j<ilosc_wierzcholkow+2;j++)
    {




									if (graf[numer][j][2]!=0)
										{cout<<"numer="<<numer<<" odleglosc= "<<graf[numer][j][2]<<endl;
											if(d[j]>d[numer]+graf[numer][j][2])
											{
												p[j]=numer;
                                               // cout<<"pi=i=" <<p[j]<<endl;
												d[j]=d[numer]+graf[numer][j][2];
												//cout<<"dj=di+graf="<< d[j]<<endl<<endl;
												wynik = d[j];



											}//else cout<<"mniejsze"<<endl<<endl;
										}//else cout<<"gowno"<<endl<<endl;

								}
//wyszukiwanie kolejnego wierzcholka o minimalnej dlugosci do przetworzenia
				for (int k=1; k<ilosc_wierzcholkow+2; k++)
					{

					    //cout<<"dk="<<d[k]<<endl;
					    //cout<<"wynik="<<wynik<<endl;
						if (graf[numer][k][2]!=0)
							{
							    //if(k==ilosc_wierzcholkow+1)
                                 // cout<<"znaleziono sciezke"<<endl;
							    int nowy;
								nowy = k;
								if (odwiedzone[nowy]==false){
                                        odwiedzone[nowy]=true;
                               cout<<"pkt nowy "<<nowy<<" zostal zbanowany"<<endl;

								kolejkaDoPrzetworzenia.push(nowy);
								}
								//cout<<"nowy="<<nowy<<endl;











							}//else
							//cout<<"nie wybrano nowego punktu"<<endl;
				}
                kolejkaDoPrzetworzenia.pop();
				kolejkaPrzetworzona.push(numer);




















licznik2++;



}for(int T=0;T<ilosc_wierzcholkow+2;T++)
//cout<<d[T]<<" ";
cout<<endl;
for(int T=0;T<ilosc_wierzcholkow+2;T++){
cout<<"p[u]= "<<p[T]<<"dla t= "<<T<<" "<<endl;
cin.get();
}


cout<<endl;
queue<int> najkrotsza;
najkrotsza.push(ilosc_wierzcholkow+1);
cout<<p[ilosc_wierzcholkow+1]<<endl;
int u=ilosc_wierzcholkow+1;
int punkty;
while(d[u]!=0){
    punkty=p[u];
    u=punkty;
    najkrotsza.push(punkty);



}
int rozmiar=najkrotsza.size();
cout<<"rozmiar="<<rozmiar<<endl;
int tablica[rozmiar];
 int odejmowanie = 0;
while(najkrotsza.empty()==false)
{

   tablica[rozmiar-odejmowanie-1]= najkrotsza.front();
   najkrotsza.pop();
odejmowanie++;
}
tablica[rozmiar]=ilosc_wierzcholkow+1;
for(int T=0;T<rozmiar;T++)
    cout<<tablica[T]<<" "<<graf[tablica[T]][tablica[T]][0]<<" "<<graf[tablica[T]][tablica[T]][1]<<endl;
    int krok=0;


/////////////////////////RYSOWANIE ŚCIEŻKI /////////////////////////////////////


    while(krok<=rozmiar-2)
    {
        int wsp1=tablica[krok];
        int wsp2=tablica[krok+1];
        double dystansX = (graf[wsp1][wsp1][POZYCJA_X]-graf[wsp2][wsp2][POZYCJA_X]);
        double dystansY = (graf[wsp1][wsp1][POZYCJA_Y]-graf[wsp2][wsp2][POZYCJA_Y]);
        double dystansXY = sqrt(dystansX*dystansX+dystansY*dystansY);
        double a=dystansY/dystansX;
        double przesuniecie=0;
        if((dystansY<0)&&(dystansX<0))
            a = a;
        if((dystansY<0)&&(dystansX>0))
            a = -a;
        if((dystansY>0)&&(dystansX<0))
            a = -a;
        if((dystansY>0)&&(dystansX>0))
            a = a;
        int znakX = -1;
        if(dystansX<0)
            znakX = 1;
        int znakY = -1;
        if(dystansY<0)
            znakY = 1;
if(dystansXY<400){
    if(dystansX!=0){
            for(int i=0; i<abs((int)dystansX); i++)
            {
                x = graf[wsp1][wsp1][POZYCJA_X]+i*znakX;
                if(a!=0){
                for(int j=0; j<abs(a); j++)
                {

                    y = a*i*znakY+graf[wsp1][wsp1][POZYCJA_Y]+j;
                    if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                    {
                        obraz.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Green);
                        biale.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Green);
                         obraz.setPixel((unsigned int)(x+1),(unsigned int)(y+1),sf::Color::Red);
                        biale.setPixel((unsigned int)(x+1),(unsigned int)(y+1),sf::Color::Red);
                         obraz.setPixel((unsigned int)x+2,(unsigned int)(y+2),sf::Color::Green);
                        biale.setPixel((unsigned int)x+2,(unsigned int)(y+2),sf::Color::Green);
                    }
                }
                }
                if(dystansY==0){
                for(int j=0; j<1; j++)
                {

                    y = graf[wsp1][wsp1][POZYCJA_Y];
                    if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                    {
                        obraz.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Green);
                        biale.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Green);
                         obraz.setPixel((unsigned int)(x+1),(unsigned int)(y+1),sf::Color::Red);
                        biale.setPixel((unsigned int)(x+1),(unsigned int)(y+1),sf::Color::Red);
                         obraz.setPixel((unsigned int)x+2,(unsigned int)(y+2),sf::Color::Green);
                        biale.setPixel((unsigned int)x+2,(unsigned int)(y+2),sf::Color::Green);
                    }
                }
                }
            }
            }
            if(dystansX==0){
            for(int i=0; i<abs((int)dystansY); i++)
            {
                x = graf[wsp1][wsp1][POZYCJA_X];
                if(a!=0){
                for(int j=0; j<1; j++)
                {

                    y = graf[wsp1][wsp1][POZYCJA_Y]+i*znakY;
                    if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                    {
                        obraz.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Green);
                        biale.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Green);
                         obraz.setPixel((unsigned int)(x+1),(unsigned int)(y+1),sf::Color::Red);
                        biale.setPixel((unsigned int)(x+1),(unsigned int)(y+1),sf::Color::Red);
                         obraz.setPixel((unsigned int)x+2,(unsigned int)(y+2),sf::Color::Green);
                        biale.setPixel((unsigned int)x+2,(unsigned int)(y+2),sf::Color::Green);
                    }
                }
                }
                if(dystansY==0){
                for(int j=0; j<1; j++)
                {

                    y = graf[wsp1][wsp1][POZYCJA_Y];
                    if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                    {
                        obraz.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Green);
                        biale.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Green);
                         obraz.setPixel((unsigned int)(x+1),(unsigned int)(y+1),sf::Color::Red);
                        biale.setPixel((unsigned int)(x+1),(unsigned int)(y+1),sf::Color::Red);
                         obraz.setPixel((unsigned int)x+2,(unsigned int)(y+2),sf::Color::Green);
                        biale.setPixel((unsigned int)x+2,(unsigned int)(y+2),sf::Color::Green);
                    }
                }
                }
            }
            }
            }
if(dystansXY>600)
            {
                if(dystansX>0){
                dystansX = 865 - dystansX;

                }
              if(dystansX<0){
                dystansX = 865 + dystansX;

                }




              dystansXY = sqrt(dystansX*dystansX+dystansY*dystansY);


 if(dystansY<0)
    dystansY=-dystansY;
    a=dystansY/dystansX;


                graf[wsp1][wsp2][KRAWEDZ]=dystansXY;
                przesuniecie=0;
                for(int i=0; i<abs((int)dystansX); i++)
                {

                    x = graf[wsp1][wsp1][POZYCJA_X]-i*znakX+przesuniecie;
                    if(x>864){
                        przesuniecie= -864;

                        }
                    if(x<1){
                        przesuniecie= +864;}
if(a!=0){
                    for(double j=0; j<ceil(abs(a)); j++)
                    {
                        //y = j*zprzenakY+i*abs((int)a);
                        //y += graf[wierzcholek][wierzcholek][POZYCJA_X];
                        y = a*i*znakY+graf[wsp1][wsp1][POZYCJA_Y]+j;

                        if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                        {

                            obraz.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Red);
                            biale.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Red);
                        }
                    }}
                    if(dystansY==0){
                    for(double j=0; j<1; j++)
                    {
                        //y = j*zprzenakY+i*abs((int)a);
                        //y += graf[wierzcholek][wierzcholek][POZYCJA_X];
                        y = graf[wsp1][wsp1][POZYCJA_Y];

                        if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                        {

                            obraz.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Red);
                            biale.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Red);
                        }
                    }}

                    }}
        krok++;
    }*/

     for(int wierzcholek = 0; wierzcholek<ilosc_wierzcholkow; wierzcholek++)
    {

    }
    for(int wierzcholek=0; wierzcholek<ilosc_wierzcholkow+2; wierzcholek++)
    {
        obraz.copy(kwadrat,graf[wierzcholek][wierzcholek][POZYCJA_X],graf[wierzcholek][wierzcholek][POZYCJA_Y]);
    }


    //kwadrat.copy(obraz,3046,779);
    //kwadrat.copy(obraz,1783,568);
    //sf::vector2u wektor;
    //wektor = mapa.getsize();
    //unsigned int wartosc = wektor.x;
    sf::Vector2u windowSize = window.getSize();
    sf::Texture texture;
    texture.create(windowSize.x, windowSize.y);
    texture.update(window);
    sf::Image screenshot = texture.copyToImage();


    sprite.setTexture(texture);
    //sprite.scale(SKALA,SKALA);
    //sf::RenderWindow::capture();
    if (!biale.saveToFile("krawedzie.png"))
        return -1;
    if (!krawedzie.loadFromFile("krawedzie.png"))
    {
        return 1;
        // error...
    }
    sprite2.setTexture(krawedzie);
    if (!obraz.saveToFile("result.png"))
        return -1;
    if (!mapaGotowa.loadFromFile("result.png"))
    {
        return 1;
        // error...
    }
    //sprite.setTexture(mapa);
    //sprite.scale(SKALA,SKALA);
    //dijkstra(graf, 0);
// PETLA G£ÓWNA RYSUJ¥CA @@@@@@@@@@@@@@@@@@@@@@@@@@@@
// PETLA G£ÓWNA RYSUJ¥CA @@@@@@@@@@@@@@@@@@@@@@@@@@@@
// PETLA G£ÓWNA RYSUJ¥CA @@@@@@@@@@@@@@@@@@@@@@@@@@@@
// PETLA G£ÓWNA RYSUJ¥CA @@@@@@@@@@@@@@@@@@@@@@@@@@@@
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.draw(sprite2);
        window.display();
    }

    for(int i=0;i<=865;i++)
    {
        for(int j=0;j<=579;j++)
        {
            delete[] graf[i][j];
        }
            delete[] graf[i];

    }
            delete[] graf;


    return 0;
}
