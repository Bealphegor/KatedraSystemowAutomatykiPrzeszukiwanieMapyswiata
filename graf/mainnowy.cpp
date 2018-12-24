#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <cmath>
#include <queue>
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
    int ilosc_wierzcholkow = 200;
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

// ZAPISYWANIE POZYCJI PIERWSZEGO I OSTATNIEGO PUNKTU

    double graf[ilosc_wierzcholkow+2][ilosc_wierzcholkow+2][4];
    graf[0][0][POZYCJA_X]=791;
    graf[0][0][POZYCJA_Y]=195;
    graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_X]=465;
    graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_Y]=136;
    obraz = mapa.copyToImage();
    sprite.setTexture(mapa);
    //sprite.setTextureRect();
    window.draw(sprite);
int odleglosc;
    shape.setFillColor(sf::Color::Yellow);
    bool byloCzarne;
    bool byloBiale;
    int metoda=0;
    if (metoda==2)
        odleglosc = 200;
    if (metoda==1)
        odleglosc=400;
    if(metoda==0)
        odleglosc=200;
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


    for(int wierzcholek=0; wierzcholek<ilosc_wierzcholkow; wierzcholek++)
    {
        byloCzarne = false
        int kratka=1;
        for(int i=0; i<10*kratkaX;i++){
        for(int j=0; j<6*kratkaY;i++){
           pozycjaX=i;
        pozycjaY=j;
            if((pozycjaX > i)&&(pozycjaX + i < OKNO_X)&&(pozycjaY > i)&&(pozycjaY + i < OKNO_Y))
            {
                if((obraz.getPixel(pozycjaX,pozycjaY).r <200)&&(obraz.getPixel(pozycjaX,pozycjaY).g <200)&&(obraz.getPixel(pozycjaX,pozycjaY).b <200))
                    byloCzarne =true;

            }



        }

        }


        if(byloCzarne)
        {
            wierzcholek--;
        }
        else// TWORZENIE WIERZCHOŁKÓW GRAFU I ZAPISYWANIE ICH POZYCJI
        {
            graf[wierzcholek+1][wierzcholek+1][POZYCJA_X] = 10*kratka-5;
            graf[wierzcholek+1][wierzcholek+1][POZYCJA_Y] = 6*kratka-3;
            shape.setPosition(pozycjaX,pozycjaY);
            window.draw(shape);
        }
        if(kratkaY<80)
            kratka++;
            else{
                kratkaY=1;
                if (kratkaX<85)
                    kratkaX++;
                else
                    break;

    }
}
}
if(metoda==0){


    for(int wierzcholek=0; wierzcholek<ilosc_wierzcholkow; wierzcholek++)
    {
        byloCzarne = false;
        pozycjaX=rand()%ROZMIAR_X;
        pozycjaY=rand()%ROZMIAR_Y;
        for(int i=0; i<5; i++) // SPRAWDZANIE CZY NIE TRAFILIŚMY NA LĄD
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

graf[1][1][POZYCJA_X]=326;
graf[1][1][POZYCJA_Y]=502;
graf[2][2][POZYCJA_X]=18;
graf[2][2][POZYCJA_Y]=407;
graf[3][3][POZYCJA_X]=31;
graf[3][3][POZYCJA_Y]=418;
graf[4][4][POZYCJA_X]=502;
graf[4][4][POZYCJA_Y]=409;
graf[5][5][POZYCJA_X]=728;
graf[6][6][POZYCJA_Y]=408;
graf[7][7][POZYCJA_X]=800;
graf[7][7][POZYCJA_Y]=439;
graf[8][8][POZYCJA_X]=842;
graf[8][8][POZYCJA_Y]=363;
graf[9][9][POZYCJA_X]=862;
graf[9][9][POZYCJA_Y]=408;
    int ktory=10;
for(int i=1;i<864;i+=1){
        cout<<"i="<<i<<endl;
if(ktory==ilosc_wierzcholkow+1)
                break;
    for(int j=1;j<578;j+=1){
if(ktory==ilosc_wierzcholkow+1)
                break;

        pozycjaX=i;
        pozycjaY=j;

        if((obraz.getPixel(pozycjaX,pozycjaY).r >200)&&(obraz.getPixel(pozycjaX,pozycjaY).g >200)&&(obraz.getPixel(pozycjaX,pozycjaY).b >200)
           &&(obraz.getPixel(pozycjaX+3,pozycjaY-3).r >200)&&(obraz.getPixel(pozycjaX+3,pozycjaY-1).g >200)&&(obraz.getPixel(pozycjaX+3,pozycjaY-3).b >200)
           &&(obraz.getPixel(pozycjaX+3,pozycjaY+3).r >200)&&(obraz.getPixel(pozycjaX+3,pozycjaY+1).g >200)&&(obraz.getPixel(pozycjaX+3,pozycjaY+3).b >200)
           &&(obraz.getPixel(pozycjaX+3,pozycjaY).r <200)&&(obraz.getPixel(pozycjaX+3,pozycjaY).g <200)&&(obraz.getPixel(pozycjaX+1,pozycjaY).b <200)
           ){
cout<<"znaleziono z lewej"<<endl;


j+=100;
i+=1;
            graf[ktory][ktory][POZYCJA_X] = pozycjaX;

            graf[ktory][ktory][POZYCJA_Y] = pozycjaY;
            cout<<"X="<<pozycjaX<<"  Y="<<pozycjaY<<endl;

            shape.setPosition(pozycjaX,pozycjaY);
            window.draw(shape);
            ktory++;
            cout<<"ilosc"<<ktory<<endl;
              cout<<"iloscW"<<ilosc_wierzcholkow<<endl;

            if(ktory==ilosc_wierzcholkow)
                break;
           }if((obraz.getPixel(pozycjaX,pozycjaY).r >200)&&(obraz.getPixel(pozycjaX,pozycjaY).g >200)&&(obraz.getPixel(pozycjaX,pozycjaY).b >200)
           &&(obraz.getPixel(pozycjaX-1,pozycjaY-1).r >200)&&(obraz.getPixel(pozycjaX-1,pozycjaY-1).g >200)&&(obraz.getPixel(pozycjaX-1,pozycjaY-1).b >200)
           &&(obraz.getPixel(pozycjaX-1,pozycjaY+1).r >200)&&(obraz.getPixel(pozycjaX-1,pozycjaY+1).g >200)&&(obraz.getPixel(pozycjaX-1,pozycjaY+1).b >200)
           &&(obraz.getPixel(pozycjaX-1,pozycjaY).r <200)&&(obraz.getPixel(pozycjaX-1,pozycjaY).g <200)&&(obraz.getPixel(pozycjaX-1,pozycjaY).b <200)
           ){
cout<<"znaleziono z prawej"<<endl;

j+=100;
i+=1;

            graf[ktory][ktory][POZYCJA_X] = pozycjaX;

            graf[ktory][ktory][POZYCJA_Y] = pozycjaY;
            cout<<"X="<<pozycjaX<<"  Y="<<pozycjaY<<endl;

            shape.setPosition(pozycjaX,pozycjaY);
            window.draw(shape);
            ktory++;
            cout<<"ilosc"<<ktory<<endl;
              cout<<"iloscW"<<ilosc_wierzcholkow<<endl;
            cin.get();
            if(ktory==ilosc_wierzcholkow)
                break;
           }


}
}
graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_X]=465;
    graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_Y]=136;}

    for(int i=0;i<ilosc_wierzcholkow+2;i++)



    //RYSOWANIE PIERWSZEGO I OSTATNIEGO WĘZŁA
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(graf[0][0][POZYCJA_X], graf[0][0][POZYCJA_Y]);
    window.draw(shape);

    shape.setFillColor(sf::Color::Red);
    shape.setPosition(graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_X],graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_Y]);
    window.draw(shape);

    // ZEROWANIE KRAWĘDZI GRAFU

    for(int wierzcholek = 0; wierzcholek<ilosc_wierzcholkow+2; wierzcholek++)
    {
        for(int wierzcholek2 = 0; wierzcholek2<ilosc_wierzcholkow+2; wierzcholek2++)
        {
            graf[wierzcholek][wierzcholek2][KRAWEDZ]=0;
            graf[wierzcholek][wierzcholek2][SCIEZKA]=0;
        }
    }


    //SPRAWDZANIE CZY MOŻNA UTWORZYĆ KRAWĘDŹ I TWORZENIE ICH
    for(int wierzcholek = 0; wierzcholek<ilosc_wierzcholkow+1; wierzcholek++)
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
            if(dystansXY<odleglosc)
            {
                for(int i=0; i<abs((int)dystansX); i++)
                {
                    x = graf[wierzcholek][wierzcholek][POZYCJA_X]+i*znakX;
                    for(int j=0; j<ceil(abs(a)); j++)
                    {
                        y = a*i*znakY+graf[wierzcholek][wierzcholek][POZYCJA_Y]+j;
                        if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                        {
                            if((obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).r <200)&&(obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).g <200)&&(obraz.getPixel((unsigned int)x,(unsigned int)(y/*+i*/)).b <200))
                                byloCzarne = true;
                        }
                    }
                }
                if(byloCzarne)
                    continue;
                graf[wierzcholek][wierzcholek2][KRAWEDZ]=dystansXY;
                for(int i=0; i<abs((int)dystansX); i++)
                {
                    x = graf[wierzcholek][wierzcholek][POZYCJA_X]+i*znakX;
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
                    }}}
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

   for (int i = 0;i<ilosc_wierzcholkow+2;i++)
                        cout<<"od zera"<<graf[0][i][2];

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
		cout<<p[x]<<" ";
	}

queue <int> kolejkaDoPrzetworzenia;
queue <int> kolejkaPrzetworzona;

kolejkaDoPrzetworzenia.push(0);
int licznik2=0;
while (kolejkaDoPrzetworzenia.empty()==false){
       // cout<<"szuka";
if (licznik2==1000000){
        cout<<"zjebalo sie";
    break;
    }
int numer= kolejkaDoPrzetworzenia.front();
odwiedzone[numer]=true;
cout<<"odwiedzono"<<numer<<endl;

cout<<"numer="<<numer<<" "<<graf[numer][numer][0]<<" "<<graf[numer][numer][1]<<endl;

if (numer == ilosc_wierzcholkow+1){
        kolejkaPrzetworzona.push(numer);
				kolejkaDoPrzetworzenia.pop();
    break;
}
for(int j=0;j<ilosc_wierzcholkow+2;j++)
    {



									if (graf[numer][j][2]!=0)
										{
											if(d[j]>d[numer]+graf[numer][j][2])
											{

												p[j]=numer;
                                                cout<<"pi=i=" <<p[j]<<endl;
												d[j]=d[numer]+graf[numer][j][2];
												cout<<"dj=di+graf="<< d[j]<<endl<<endl;
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
							    if(k==ilosc_wierzcholkow+1)
                                  cout<<"znaleziono sciezke"<<endl;
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

				kolejkaPrzetworzona.push(numer);
				kolejkaDoPrzetworzenia.pop();



















licznik2++;



}for(int T=0;T<ilosc_wierzcholkow+2;T++)
cout<<d[T]<<" ";
cout<<endl;
for(int T=0;T<ilosc_wierzcholkow+2;T++)
cout<<"p[u]= "<<p[T]<<"dla t= "<<T<<" "<<endl;

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
if(dystansXY<odleglosc){
            for(int i=0; i<abs((int)dystansX); i++)
            {
                x = graf[wsp1][wsp1][POZYCJA_X]+i*znakX;
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
}if(dystansXY>600)
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
                    }}}
        krok++;
    }
*/
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

    return 0;
}
