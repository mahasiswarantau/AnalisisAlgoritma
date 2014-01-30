#include <stdio.h>
#include <conio.h>

struct btreenode
{
    struct btreenode *leftchild ;
    int data ;
    struct btreenode *rightchild ;
} ;

void insert ( struct btreenode **, int ) ;
void inorder ( struct btreenode * ) ;

int main(int argc, char *argv[])
{
    struct btreenode *bt ;
    int wortel = 1;
    int kelinci = 3;
    int singa = 2;
    int pemburu = 4;
    int arr[4] = { wortel, kelinci, singa, pemburu } ;//urutan karakter dalam game
    int i ;

    bt = NULL ;

    system("cls");

    printf ( "RIVER CROSSING\n" ) ;

    printf ( "\nSisi Kanan :\n" ) ;
    for ( i = 0 ; i <= 3 ; i++ )
        printf ( "%d\t", arr[i] ) ;

    for ( i = 0 ; i <= 3 ; i++ )
        insert ( &bt, arr[i] ) ;

    printf ( "\n\nSisi Kiri :\n" ) ;
    inorder ( bt ) ;

    getch( ) ;	
    return 0;
}

void insert ( struct btreenode **sr, int num )
{
    if ( *sr == NULL )
    {
        *sr = malloc ( sizeof ( struct btreenode ) ) ;

        ( *sr ) -> leftchild = NULL ;
        ( *sr ) -> data = num ;
        ( *sr ) -> rightchild = NULL ;
    }
    else
    {
        if ( num < ( *sr ) -> data )
            insert ( &( ( *sr ) -> leftchild ), num ) ;
        else
            insert ( &( ( *sr ) -> rightchild ), num ) ;
    }
}

void inorder ( struct btreenode *sr )
{
    if ( sr != NULL )
    {
        inorder ( sr -> leftchild ) ;
        printf ( "%d\t", sr -> data ) ;
        inorder ( sr -> rightchild ) ;
    }
}
