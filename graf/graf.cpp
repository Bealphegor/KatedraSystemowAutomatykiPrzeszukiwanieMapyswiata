#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <cmath>
#include <queue>
#define POZYCJA_X 0
#define POZYCJA_Y 1
#define KRAWEDZ 2
#define SCIEZKA 3
#include <iostream>
#define ILOSC_WIERZCHOLKOW 200
#define Ds 200
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
	int ilosc_wierzcholkow = ILOSC_WIERZCHOLKOW;
	int pozycjaX;
	int pozycjaY;
	int x,y;
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

	double graf[ILOSC_WIERZCHOLKOW+2][ILOSC_WIERZCHOLKOW+2][4];
    graf[0][0][POZYCJA_X]=791;
    graf[0][0][POZYCJA_Y]=195;
    graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_X]=465;
    graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_Y]=136;
    obraz = mapa.copyToImage();
    sprite.setTexture(mapa);
    //sprite.setTextureRect();
    window.draw(sprite);

    shape.setFillColor(sf::Color::Yellow);
    bool byloCzarne;
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

    /*graf[0][0][POZYCJA_X]=370;
    graf[0][0][POZYCJA_Y]=420;
    graf[1][1][POZYCJA_X]=457;
    graf[1][1][POZYCJA_Y]=319;
    graf[2][2][POZYCJA_X]=430;
    graf[2][2][POZYCJA_Y]=437;*/
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
            if(dystansXY<200)
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


//algorytm djikstry
      int b=0;
	int n = 102;
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

	for(int x = 1; x<n;x++)
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
if (licznik2==100000000)
    break;
int numer= kolejkaDoPrzetworzenia.front();
//cout<<"numer="<<numer<<endl;
if (numer == 101){
        kolejkaPrzetworzona.push(numer);
				kolejkaDoPrzetworzenia.pop();
    break;
}
for(int j=0;j<102;j++)
    {
								    /*cout<<"j="<<j<<endl;
								    cout<<"i="<<numer<<endl;
								    cout<<"pj test="<<p[j]<<endl;
								    cout<<"dj test="<<d[j]<<endl<<endl;
								    cout<<"pi test="<<p[pkt]<<endl;
								    cout<<"di test="<<d[pkt]<<endl<<endl;
								    cout<<"graf test="<<graf[pkt][j][2]<<endl;*/
								    //std::cin.ignore();



									if (graf[numer][j][2]!=0)
										{
											if(d[j]>d[numer]+graf[numer][j][2])
											{

												p[j]=numer;
                                                //cout<<"pi=i=" <<p[j]<<endl;
												d[j]=d[numer]+graf[numer][j][2];
												//cout<<"dj=di+graf="<< d[j]<<endl<<endl;
												wynik = d[j];



											}//else cout<<"mniejsze"<<endl<<endl;
										}//else cout<<"gowno"<<endl<<endl;

								}
//wyszukiwanie kolejnego wierzcholka o minimalnej dlugosci do przetworzenia
				for (int k=1; k<102; k++)
					{
					   // cout<<"k="<<k<<endl;
					   // cout<<"dk="<<d[k]<<endl;
					  //  cout<<"wynik="<<wynik<<endl;
//cout<<"sciezka do k="<<k<<"rowna jest"<<graf[numer][k][2];
						if (graf[numer][k][2]!=0)
							{
							    if(k==101)
                                  cout<<"znaleziono sciezke"<<endl;
							    int nowy;
								nowy = k;
								kolejkaDoPrzetworzenia.push(nowy);
								//cout<<"nowy="<<nowy<<endl;











							}//else
							//cout<<"nie wybrano nowego punktu"<<endl;
				}
				kolejkaPrzetworzona.push(numer);
				kolejkaDoPrzetworzenia.pop();



















licznik2++;



}for(int T=0;T<102;T++)
cout<<d[T]<<" ";
cout<<endl;
for(int T=0;T<102;T++)
cout<<"p[u]= "<<p[T]<<"dla t= "<<T<<" "<<endl;

cout<<endl;
queue<int> najkrotsza;
najkrotsza.push(101);
cout<<p[101]<<endl;
int u=101;
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
tablica[rozmiar]=ilosc_wierzcholkow;
cout<<"jestesmy tutaj"<<endl;
for(int T=0;T<rozmiar;T++){
cout<<"jestesmy tutaj"<<endl;
    cout<<tablica[T]<<" "<<graf[1][1][POZYCJA_X]<<" "<<graf[tablica[T]][tablica[T]][POZYCJA_Y]<<endl;
}
    int krok=0;
while(krok<=rozmiar-2){
int wsp1=tablica[krok];
int wsp2=tablica[krok+1];
                double dystansX = (graf[wsp1][wsp2][POZYCJA_X]-graf[wsp1][wsp2][POZYCJA_X]);
                double dystansY = (graf[wsp1][wsp2][POZYCJA_Y]-graf[wsp1][wsp2][POZYCJA_Y]);
                double dystansXY = sqrt(dystansX*dystansX+dystansY*dystansY);
                double a=dystansY/dystansX;
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
                if(dystansXY<200)
                {
                    for(int i=0; i<abs((int)dystansX); i++)
                    {
                        x = graf[wsp1][wsp1][POZYCJA_X]+i*znakX;
                        for(int j=0; j<abs(a); j++)
                        {
                            y = a*i*znakY+graf[wsp1][wsp1][POZYCJA_Y]+j;
                            if((y<ROZMIAR_Y)&&(x<ROZMIAR_X)&&(y>0)&&(x>0))
                            {
                                obraz.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Red);
                                biale.setPixel((unsigned int)x,(unsigned int)(y),sf::Color::Red);
                            }
                        }
                    }
                }
          krok++;
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
