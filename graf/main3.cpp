#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

#define POZYCJA_X 0
#define POZYCJA_Y 1
#define KRAWEDZ 2
#define ODLEGLOSC 3

#define PROMIEN 5.0

#define OKNO_X 892
#define OKNO_Y 600

#define SKALA 0.248329621380

#define ROZMIAR_X 3592
#define ROZMIAR_Y 2416

using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(OKNO_X, OKNO_Y), "SFML window");
	window.setVerticalSyncEnabled(true);
	sf::Texture mapa;
    sf::Texture kwadratTexture;
    sf::Texture mapaGotowa;
	sf::Image obraz;
	sf::Image kwadrat;
	sf::Sprite sprite;
	sf::Color kolor;
    sf::CircleShape shape(PROMIEN);
    shape.setOrigin(PROMIEN,PROMIEN);
	int ilosc_wierzcholkow = 100;
	int pozycjaX;
	int pozycjaY;
	srand (time(NULL));
    //unsigned int maximum = sf::Texture::getMaximumSize();
	int debuging = 0;

	if (!mapa.loadFromFile("a.png"))
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



// RYSOWANIE PIERWSZEGO I OSTATNIEGO PUNKTU

	double graf[ilosc_wierzcholkow+2][ilosc_wierzcholkow+2][3];
    graf[0][0][POZYCJA_X]=3046;
    graf[0][0][POZYCJA_Y]=779;
    graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_X]=1783;
    graf[ilosc_wierzcholkow+1][ilosc_wierzcholkow+1][POZYCJA_X]=568;
    obraz = mapa.copyToImage();
    sprite.setTexture(mapa);



    //shape.setFillColor(sf::Color::Green);
    //shape.setPosition(3046, 779);
    //sprite.draw(shape);
    //shape.setPosition(0, 0);
    //sprite.draw(shape);

    //shape.setFillColor(sf::Color::Red);
    //shape.setPosition(1783,568);
    //sprite.draw(shape);



    //shape.setFillColor(sf::Color::Yellow);
    bool byloCzarne;
	for(int wierzcholek=0; wierzcholek<ilosc_wierzcholkow; wierzcholek++)
	{
        byloCzarne = false;
		pozycjaX=rand()%ROZMIAR_X;
		pozycjaY=rand()%ROZMIAR_Y;
		for(int i=0; i<5; i++)
        {
            if((pozycjaX > i)&&(pozycjaX + i < OKNO_X)&&(pozycjaY > i)&&(pozycjaY + i < OKNO_Y))
            {
                if((obraz.getPixel(pozycjaX+i,pozycjaY+i).r <200)&&(obraz.getPixel(pozycjaX+i,pozycjaY+i).g <200)&&(obraz.getPixel(pozycjaX+i,pozycjaY+i).b <200))
                    byloCzarne =true;
                if((obraz.getPixel(pozycjaX-i,pozycjaY-i).r <200)&&(obraz.getPixel(pozycjaX-i,pozycjaY-i).g <200)&&(obraz.getPixel(pozycjaX-i,pozycjaY-i).b <200))
                    byloCzarne =true;
            }
        }
		if(byloCzarne)// && kolor.g == 0 && kolor.b = 0)
		{
			wierzcholek--;
		}
		else
		{
			graf[wierzcholek+1][wierzcholek+1][POZYCJA_X] = pozycjaX;
			graf[wierzcholek+1][wierzcholek+1][POZYCJA_Y] = pozycjaY;
            shape.setPosition(pozycjaX,pozycjaY);
            window.draw(shape);
		}
	}
	/*for(int wierzcholek = 0; wierzcholek<ilosc_wierzcholkow; wierzcholek++)
    {
        for(int wierzcholek2 = 0; wierzcholek2<ilosc_wierzcholkow; wierzcholek2++)
        {

        }
    }*/
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
    //texture.create(windowSize.x, windowSize.y);
    texture.update(window);
    sf::Image screenshot = texture.copyToImage();

    //sprite.setTexture(texture);
    sprite.scale(SKALA,SKALA);
    //sf::RenderWindow::capture();


    if (!obraz.saveToFile("result.png"))
        return -1;
    if (!mapaGotowa.loadFromFile("result.png"))
	{
	    return 1;
		// error...
	}
    sprite.setTexture(mapaGotowa);
    //sprite.scale(SKALA,SKALA);

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
        window.display();
    }

	return 0;
}
