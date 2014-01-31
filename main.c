#include <stdio.h>
#include <conio2.h>

struct btreenode
{
    struct btreenode *leftchild ;
    int data ;
    struct btreenode *rightchild ;
} ;

void kanan ( struct btreenode **, int ) ;
void kiri ( struct btreenode * ) ;

int main(int argc, char *argv[])
{
    struct btreenode *bt ;
    int rumput = 1;
    int kambing = 3;
    int serigala = 2;
    int pemburu = 4;
    int arrnull[4] = { 0,0,0,0 };
    int arr[4] = { rumput, kambing, serigala, pemburu } ;//urutan karakter dalam game
    int i ;

    bt = NULL ;

    system("cls");

    printf ( "RIVER CROSSING\n" ) ;
    
    //sebelum dimulai
    printf ( "\n\nSisi Kiri :\n" ) ;
    for ( i = 0 ; i <= 3 ; i++ ){
        gotoxy(1+(i*5),5);printf ( "%d", arrnull[i] ) ;
    }

    gotoxy(25,4);printf ( "Sisi Kanan :" ) ;
    for ( i = 0 ; i <= 3 ; i++ ){
        gotoxy(25+(i*5),5);printf ( "%d", arr[i] ) ;
    }

    //setelah selesai
    for ( i = 0 ; i <= 3 ; i++ )
        kanan ( &bt, arr[i] ) ;

    printf ( "\n\nSisi Kiri :\n" ) ;
    gotoxy(1,8);kiri ( bt ) ;

    gotoxy(25,7);printf ( "Sisi Kanan :" ) ;
    for ( i = 0 ; i <= 3 ; i++ ){
        gotoxy(25+(i*5),8);printf ( "%d", arrnull[i] ) ;
    }
    
    getch( ) ;	
    return 0;
}

void kanan ( struct btreenode **sr, int num )
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
            kanan ( &( ( *sr ) -> leftchild ), num ) ;
        else
            kanan ( &( ( *sr ) -> rightchild ), num ) ;
    }
}

void kiri ( struct btreenode *sr )
{
    if ( sr != NULL )
    {
        kiri ( sr -> leftchild ) ;
        printf ( "%d    ", sr -> data ) ;
        kiri ( sr -> rightchild ) ;
    }
}
