#include <iostream>
using namespace std;

const int N = 30;
struct drzewo	//struktura drzewa 
{
	int var;
	drzewo* left = nullptr; //syn z lewej
	drzewo* right = nullptr;	//syn z prawej
	drzewo* parent = nullptr;	//rodzic zeby bylo ciekawiej
};

drzewo* insert_node(drzewo* node, int key)	//funkcja dodawania nowego elementu do drzewa
{
	if (node == nullptr)	//jesli pod nami juz nie ma nic to dodajmy 
	{
		node = new drzewo;	//alokujemy pamiec dla naszego wezla
		node->var = key;	//wypelniamy kluczem
		node->left = nullptr; //w sumie tego nawet nie trzeba bo w strucie juz na starcie wypelniamy nulami ale zeby bylo bardziej czytelne
		node->right = nullptr;
		node->parent = nullptr;
	}
	else if (node->var < key) //jesli wartosc w drzewie jest wieksza niz klucz
	{
		node->right = insert_node(node->right, key);	//rekurencja prawego poddrzewa (szukanie wolnego miejsca w drzewie)
		node->right->parent = node; //no i dopisujemy rodzica 
	}
	else
	{
		node->left = insert_node(node->left, key);	//rekurencja lewego poddrzewa (szukanie wolnego miejsca w drzewie)
		node->left->parent = node;	//dopisujemy rodzica
	}

	return node; //zwracamy wezel 
}
void inorder(drzewo* node)	//wypisywanie inorder
{
	if (node != nullptr)	//jesli nie wskazuje na nula 
	{
		inorder(node->left);	//przejdz do lewego poddrzewa
		cout << node->var << ","; 	//wypisz
		inorder(node->right);	//przejdz do prawego poddrzewa
	}
}
void preorder(drzewo* node) //wypisywanie preorder
{
	if (node != nullptr) //jesli nie nul
	{
		cout << node->var << "," ; //wypisz wartosc
		preorder(node->left);	//przejdz do lewego poddrzewa
		preorder(node->right);	//przejdz do prawego poddrzewa
	}
}
void postorder(drzewo* node) //wypisywanie postorder
{
	if (node != nullptr)	//jesli nie nil
	{
		postorder(node->left);	//przechodzimy do lewego poddrzewa
		postorder(node->right);	//przechodzimy do prawego poddrzewa
		cout << node->var <<","; 	//wypisywanie
	}
}
// uczywiscie te fukncje sa rekurencyjne  wiec kolejnosc wypisywanie bedzie inna dla tego drzewa

void find(drzewo* node, int key, char* path) //znajdowanie klucza w drzewie
{
	int i = 0;	// zmienna do sciezki
	while (node->left != nullptr && node->right != nullptr && key != node->var)	//jesli nie wyszlismy poza drzewo i nie znalezlismy JESZCZE klucza
	{
		if (key < node->var)	//klucz mniejszy niz wartosc
			path[i] = 'L', node = node->left;		//idziemy w lewo i to markujemy
		else                                       //wpp idziemy w prawo i markujemy
			path[i] = 'P', node = node->right;
		i++; //iterujemy sciezke
	}
	if (node->var == key)//jak znajdziemy klucz
	{
		cout << "Znaleziono wartosc w drzewie! Sciezka to: " << endl;
		for (int k = 0;k < i;k++)
			cout << path[k] << " ";	//to wypisujemy sciezke
	}
	else
		cout << "Nie znaleziono wartosci w drzwie ):" << endl; //a jak nie to nie xD
}
int min(drzewo* root)	//funkcja znajdywania min
{
	while (root->left != nullptr)	//idziemy caly czas w lewo po drzewie bo tam bedzie najmniejsza wartosc
		root = root->left;
	return root->var; //zwracamy najmniejsza wartosc 
}
int max(drzewo* root)
{
	while (root->right != nullptr) //idziemy caly czas w prawo po drzewie bo tam bedzie najwieksza wartosc
		root = root->right;
	return root->var;//zwracamy maxa
}

void remove(drzewo* node, int key) //usuwanie elementu z drzewa
{
	while (node->left != nullptr && node->right != nullptr && key != node->var) //najpierw musimy go znalezc 
	{
		if (key < node->var)
			node = node->left;
		else
			node = node->right;
	}


	if (node->var == key) //jak go znajdziemy
	{
		if (node->left == nullptr && node->right == nullptr) //jezeli to lisc 
		{
			if (node->parent->var < key) //jezeli to prawy lisc rodzica
				node->parent->right = nullptr;	//rodzic z prawej wskazuje na nul
			else                          //jezeli lewy
				node->parent->left = nullptr;//rodzic z lewej wskazuje na nul
			delete node;
		}
		/*else if (node->left == nullptr && node->right != nullptr) {             //tego jednak nie trzeba
			node->right->parent = node->parent;
			node = node->right;
		}
		else if (node->left != nullptr && node->right == nullptr) {
			node->left->parent = node->parent;
			node = node->left;
		}*/
		else  //wpp
		{
			drzewo* roboczy = node; // zmienna robocza
			while (roboczy->right != nullptr)//przechodzimy w prawo po drzewie
			{
				roboczy->var = roboczy->right->var;	//podmienimay wartosci "przenoszac" wartosci w gore 
				roboczy = roboczy->right; //idziemy w prawy dol
			}
			roboczy->parent->right = nullptr; // jak jestesmy na koncu to rodzic musi wskazywac na null
			delete roboczy;	// usuwamy ostatni element z prawej strony 

		}
		cout << "Usunieto element! " << key << endl; //wypisujemy usuniety element
	}
	else
		cout << "Nie ma takiego klucza!" << endl; //niepowodzenie

}

int main()
{
	int tab[N] = { 78, 12, 16, 38, 86, 11, 57, 19, 35, 31, 34, 22, 90, 98, 50,65, 94, 51, 47, 97, 13, 73, 40, 68, 63, 39, 93, 87, 58, 10 }; //nasza tablica
	drzewo* root = new drzewo;	//tworzymy  korzen
	root->var = tab[0];	//i go od razu wypelniamy zeby nasz algorytm dzialal poprawnie
	for (int i = 1;i < N;i++)
		root = insert_node(root, tab[i]);	//reszte elementow z tablicy dodajemy funkcja insert (wiec nie trzeba pozniej testowac funkcji insert)
	//cout << root->left->var<<endl;
	cout << "Inorder: " << endl;
	inorder(root);	//wypisywanie inorder [Nalezy odkomentowac w celu sprawdzenia !]
	cout << endl;
	cout <<"Preorder: "<< endl;
	preorder(root);	//wypisywanie preorder [Nalezy odkomentowac w celu sprawdzenia !]
	cout << endl;
	cout <<"Postorder: "<< endl;
	postorder(root);	//wypisywanie postorder
	//char path[N];	//a taka dodatkowa tablica na droge dla naszego drzewa od korzenia do klucza
	//find(root,15,path);	//szukamy klucza 15 w drzewie
	//cout << endl;
	////wstawianie juz bylo zrealizowane wczesniej.
	//cout<<"Minimum wynosi: " <<min(root)<<endl;	//funckja min
	//cout << "Maximum wynosi: " << max(root) << endl;	//funkcja max
	//remove(root, 15);	//usuwamy dziecko
	//postorder(root);	//wypisujemy
	//remove(root, 38);	//a tu korzen zeby sprawdzic czy tez dziala
	//postorder(root);	//wypisujemy
}

