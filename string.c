
#ifndef _STRING_C
    #define _STRING_C
#endif

#ifndef _STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _STRING_H
    #include <string.h>
#endif





typedef struct stringDNode
{
    char Value;
    struct stringDNode *Previous;
    struct stringDNode *Next;
} stringDNode;

typedef struct string
{
    struct stringDNode *H;
    struct stringDNode *T;
    int length;
} string;



void funcstringDNodeInit (stringDNode *pDNode)
{
    pDNode->Value = 0;
    pDNode->Next = NULL;
    pDNode->Previous = NULL;
}

stringDNode* funcstringDNodeCreate (char value)
{

    stringDNode *vpNew = (stringDNode*) malloc(sizeof(stringDNode));
    if ( vpNew==NULL )
    {
        printf ("\nThe Allocation has failled !!!");
        exit (1);
    }

    funcstringDNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}

stringDNode* funcstringDNodePointer (string DList, int index)
{
    stringDNode *vpCn;
    int viCn;


    if ( 0<=index )
    {
        if ( DList.length-1<index )
        {
            printf ("The index is out the range of the String !!!");
            exit (1);
        }

        vpCn = DList.H;
        for ( viCn=0; viCn<index; viCn++ )
        {
            vpCn = vpCn->Next;
        }

        return vpCn;
    }
    else
    {
        if ( DList.length<-index )
        {
            printf ("The index is out the range of the String !!!");
            exit (1);
        }

        vpCn = DList.T;
        for ( viCn=-1; index<viCn; viCn-- )
        {
            vpCn = vpCn->Previous;
        }

        return vpCn;
    }
}

void funcstringDNodeFree (stringDNode *pDNode)
{
    pDNode->Next = NULL;
    pDNode->Previous = NULL;
    pDNode->Value = 0;
    free (pDNode);
}



void funcstringInit (string *pString)
{
    pString->H = NULL;
    pString->T = NULL;
    pString->length = 0;
}

bool funcstringEmpty (string String)
{
    if ( String.length==0 )
    {
        return true;
    }

    // else
    return false;
}


// do not have a dependency
void funcstringInsert (string *pString, int index, char value)
{

    stringDNode *vpNew;
    stringDNode *vpTemp;
    stringDNode *vpCn;
    int viCn;


    
    if ( 0<=index )
    {
        
        if ( (*pString).length<index )
        {
            printf ("The index is out the range of the String !!!");
            exit (1);
        }

        vpNew = funcstringDNodeCreate (value);

        if ( (*pString).length==0 )
        {
            (*pString).H = vpNew;
            (*pString).T = vpNew;
        }
        else
        {
            if ( index==0 )
            {
                vpTemp = (*pString).H;
                (*pString).H = vpNew;

                (*pString).H->Next = vpTemp;
                vpTemp->Previous = (*pString).H;
            }
            else if ( index==(*pString).length )
            {
                vpTemp = (*pString).T;
                (*pString).T = vpNew;

                (*pString).T->Previous = vpTemp;
                vpTemp->Next = (*pString).T;
            }
            else
            {

                vpCn = (*pString).H;
                for ( viCn=0; viCn<index; viCn++ )
                {
                    vpCn = vpCn->Next;
                }
                vpTemp = vpCn;


                vpNew->Next = vpTemp;
                vpNew->Previous = vpTemp->Previous;

                vpTemp->Previous->Next = vpNew;
                vpTemp->Previous = vpNew;
            }
        }
    }
    else
    {
        if ( (*pString).length+1<-index )
        {
            printf ("The index is out the range of the String !!!");
            exit (1);
        }


        vpNew = funcstringDNodeCreate (value);

        if ( (*pString).length==0 )
        {
            (*pString).H = vpNew;
            (*pString).T = vpNew;
        }
        else
        {
            if ( index==-1 )
            {
                vpTemp = (*pString).T;
                (*pString).T = vpNew;

                (*pString).T->Previous = vpTemp;
                vpTemp->Next = (*pString).T;
            }
            else if ( index==-((*pString).length)-1 )
            {
                vpTemp = (*pString).H;
                (*pString).H = vpNew;

                (*pString).H->Next = vpTemp;
                vpTemp->Previous = (*pString).H;
            }
            else
            {
                vpCn = (*pString).T;
                for ( viCn=-1; index<viCn; viCn-- )
                {
                    vpCn = vpCn->Previous;
                }
                vpTemp = vpCn;

                vpNew->Previous = vpTemp;
                vpNew->Next = vpTemp->Next;

                vpTemp->Next->Previous = vpNew;
                vpTemp->Next = vpNew;
            }
        }
    }
        



    (*pString).length++;
}

void funcstringInsertBegin (string *pString, char value)
{
    funcstringInsert (pString, 0, value);   //&(*pString)
}

void funcstringInsertEnd (string *pString, char value)
{
    funcstringInsert (pString, pString->length, value);     // &(*pString), (*pString).length
}

/*
void funcstringInsertBegin (string *pString, char value)
{

    stringDNode *vp;
    stringDNode *vpTemp;

    vp = funcstringDNodeCreate (value);
    if ( (*pString).length==0 )
    {
        (*pString).H = vp;
        (*pString).T = vp;
    }
    else
    {
        vpTemp = (*pString).H;
        (*pString).H = vp;

        (*pString).H->Next = vpTemp;
        vpTemp->Previous = (*pString).H;
    }



    (*pString).length++;
}
*/

/*
void funcstringInsertEnd (string *pString, char value)
{

    stringDNode *vpNew;
    stringDNode *vpTemp;

    vpNew = funcstringDNodeCreate(value);
    if ( (*pString).length==0 )
    {
        (*pString).H = vpNew;
        (*pString).T = vpNew;
    }
    else
    {
        vpTemp = (*pString).T;
        (*pString).T = vpNew;

        (*pString).T->Previous = vpTemp;
        vpTemp->Next = (*pString).T;
    }



    (*pString).length++;
}
*/


char funcstringat (string pString, int index)
{

    stringDNode *vpCn;
    stringDNode *vp;
    int viCn = 0;



    vp = funcstringDNodePointer (pString, index);

    return vp->Value;
}

int funcstringIndex (string pString, char value)
{

    stringDNode *vpCn;
    int viCn;

    vpCn = pString.H;
    for ( viCn=0; viCn<pString.length; viCn++ )
    {
        if ( vpCn->Value == value )
        {
            return viCn;
        }
        
        vpCn = vpCn->Next;
    }

    printf ("The Number %c do not exist in the String !!!", value);
    exit(1);
}

int funcstringCount (string pString, char value)
{
    
    stringDNode *vpCn = pString.H;
    int viFound = 0;



    while ( vpCn!=NULL )
    {
        if ( value==vpCn->Value )
        {
            viFound ++;
        }

        vpCn = vpCn->Next;
    }

    return viFound;
}

void funcstringModify (string *pString, int index, char value)
{

    stringDNode *vpNew = funcstringDNodePointer (*pString, index);

    vpNew->Value = value;
}


void funcstringRemove (string *pString, int index)
{

    stringDNode *vp;
    stringDNode *vpTemp;



    vp = funcstringDNodePointer (*pString, index);



    if ( (*pString).length==1 )
    {
        vpTemp = vp;
        (*pString).H = NULL;
        (*pString).T = NULL;

        funcstringDNodeFree (vpTemp);
    }
    else
    {
        if ( vp==(*pString).H )
        {
            vpTemp = (*pString).H;
            (*pString).H = (*pString).H->Next;

            (*pString).H->Previous = NULL;
            funcstringDNodeFree (vpTemp);
        }
        else if ( vp==(*pString).T )
        {
            vpTemp = (*pString).T;
            (*pString).T = (*pString).T->Previous;

            (*pString).T->Next = NULL;
            funcstringDNodeFree (vpTemp);
        }
        else
        {
            vpTemp = vp;

            vpTemp->Previous->Next = vpTemp->Next;
            vpTemp->Next->Previous = vpTemp->Previous;
            funcstringDNodeFree (vpTemp);
        }
    }





    (*pString).length--;
}

void funcstringRemoveBegin (string *pString)
{
    funcstringRemove (pString, 0);  // &(*pString)
}

void funcstringRemoveEnd (string *pString)
{
    funcstringRemove (pString, pString->length-1);  // &(*pString), (*pString).length-1
}

/*
void funcstringRemoveBegin (string *pString)
{

    stringDNode *vpTemp;

    if ( (*pString).length==0 )
    {
        printf ("The String is already empty !!!");
        return;
    }


    if ( (*pString).length==1 )
    {
        vpTemp = (*pString).H;
        (*pString).H = NULL;
        (*pString).T = NULL;

        funcstringDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pString).H;
        (*pString).H = (*pString).H->Next;

        (*pString).H->Previous = NULL;
        funcstringDNodeFree (vpTemp);    
    }



    (*pString).length--;
}
*/

/*
void funcstringRemoveEnd (string *pString)
{
    
    stringDNode *vpTemp;
    

    if ( (*pString).length==0 )
    {
        printf ("The String is already empty !!!");
        return;
    }

    if ( (*pString.length==1) )
    {
        vpTemp = (*pString).H;
        (*pString).H = NULL;
        (*pString).T = NULL;

        funcstringDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pString).T;
        (*pString).T = (*pString).T->Previous;

        (*pString).T->Next = NULL;
        funcstringDNodeFree (vpTemp);
    }
    



    (*pString).length--;
}
*/


void funcstringDListClear (string *pString)
{

    while ( (*pString).length>0 )
    {
        funcstringRemove (pString, 0);  // &(*pString)
    }
}

/*
void funcstringClear (string *pString)
{


    stringDNode *vpCn;
    stringDNode *vpTemp;


    vpCn = (*pString).H;
    while ( vpCn!=NULL )
    {
        vpTemp = vpCn;
        vpCn = vpCn->Next;

        funccharDNodeFree (vpTemp);
    }


    (*pString).H = NULL;
    (*pString).T = NULL;
    (*pString).length = 0;
}
*/

bool funcstringIsUpper (string String)
{
    stringDNode *vpCn;

    vpCn = String.H;
    while ( vpCn!=NULL )
    {
        if ( vpCn->Value<65 || 95<vpCn->Value)
        {
            return false;
        }

        vpCn = vpCn->Next;
    }

    return true;
}

bool funcstringIsLower (string String)
{
    stringDNode *vpCn;

    vpCn = String.H;
    while ( vpCn!=NULL )
    {
        if ( vpCn->Value<97 || 122<vpCn->Value )
        {
            return false;
        }

        vpCn = vpCn->Next;
    }

    return true;
}

bool funcstringIsAlpha (string String)
{
    stringDNode *vpCn;
    char Value;

    vpCn = String.H;
    while ( vpCn!=NULL )
    {
        Value = vpCn->Value;
        if ( Value<65 || 95<Value   &&   Value<97 || 122<Value )
        {
            return false;
        }

        vpCn = vpCn->Next;
    }

    return true;
}

bool funcstringIsNumeric (string String)
{
    stringDNode *vpCn;

    vpCn = String.H;
    while ( vpCn!=NULL )
    {
        if ( vpCn->Value<48 || 57<vpCn->Value )
        {
            return false;
        }

        vpCn = vpCn->Next;
    }

    return true;
}

bool funcstringIsAlphaNumeric (string String)
{
    stringDNode *vpCn;

    vpCn = String.H;
    while ( vpCn!=NULL )
    {
        if ( vpCn->Value<48 || 57<vpCn->Value   &&   vpCn->Value<65 || 95<vpCn->Value   &&   vpCn->Value<97 || 122<vpCn->Value )
        {
            return false;
        }

        vpCn = vpCn->Next;
    }

    return true;
}

void funcstringLower (string *pString)
{
    stringDNode *vpCn;

    vpCn = (*pString).H;
    while ( vpCn!=NULL )
    {
        if ( 65<=vpCn->Value && vpCn->Value<=90 )
        {
            vpCn->Value = vpCn->Value +32;    
        }

        vpCn = vpCn->Next;
    }
}

void funcstringUpper (string *pString)
{
    stringDNode *vpCn;

    vpCn = (*pString).H;
    while ( vpCn!=NULL )
    {
        if ( 97<=vpCn->Value && vpCn->Value<=122 )
        {
            vpCn->Value = vpCn->Value - 32;
        }

        vpCn = vpCn->Next;
    }
}



int funcstringCompare (string String1, string String2)
{

    if ( String1.length==0 && String2.length==0 )
    {
        return 0;
    }

    if ( String1.length==0 ) // String2!=0
    {
        return -1;
    }
    
    if ( String2.length==0 ) // String1!=0
    {
        return 1;
    }

    stringDNode *vpCn1;
    stringDNode *vpCn2;

    vpCn1 = String1.H;
    vpCn2 = String2.H;
    while ( vpCn1!=NULL && vpCn2!=NULL )
    {
        if ( vpCn1->Value > vpCn2->Value )
        {
            return 1;
        }
        
        if ( vpCn1->Value < vpCn2->Value )
        {
            return -1;
        }

        vpCn1 = vpCn1->Next;
        vpCn2 = vpCn2->Next;
    }



    if ( String1.length < String2.length )
    {
        return 1;
    }

    if ( String1.length > String2.length )
    {
        return -1;
    }

    // String1.length == String2.length
    return 0;

}

void funcstringConcate (string *pString1, string String2)
{
    stringDNode *vpCn;

    vpCn = String2.H;
    while ( vpCn!=NULL )
    {

        funcstringInsertEnd (pString1, vpCn->Value); // &(*pString1)

        vpCn = vpCn->Next;
    }
}

void funcstringCopy (string *pString1, string String2)
{
    stringDNode *vpCn;

    vpCn = String2.H;
    while ( vpCn!=NULL )
    {
        funcstringInsertEnd ( pString1, vpCn->Value ); // &(*pString1)        
        vpCn = vpCn->Next;
    }
}



const int STRING_MAX_LENGTH = 101; // 100+1

void funcstringInput (string *pString)
{

    char Buffer [STRING_MAX_LENGTH];
    int viBufferSize;
    char vcClearBuffer;

    int viCn;





    printf ("Enter the String: ");
    fgets (Buffer, STRING_MAX_LENGTH, stdin);



    viBufferSize = strlen (Buffer);
    if ( Buffer[viBufferSize-1] != '\n' )
    {
        do
        {
            vcClearBuffer = getchar();
        } while ( vcClearBuffer!='\n' );
    }

    for ( viCn=0; viCn<viBufferSize; viCn++ )   // viBufferSize won't reach the '\0'
    {
        if ( Buffer[viCn]=='\n' )               // in case of the size is less than STRING_MAX_LENGTH
        {
            break;
        }
        funcstringInsertEnd (pString, Buffer[viCn]);
    }
}

void funcstringDisplay (string String)
{

    stringDNode *vpCn;
    
    if ( String.length==0 )
    {
        printf ("The String is Empty !!!\n");
        return;
    }
    
    vpCn = String.H;
    while (vpCn!=NULL)
    {
        printf ("%c", vpCn->Value);
        vpCn = vpCn->Next;
    }
    
}

void funcstringDisplayReversed (string String)
{

    stringDNode *vpCn;

    if ( String.length==0 )
    {
        printf ("The String is empty !!!\n");
        return;
    }
    
    
    vpCn = String.T;
    while ( vpCn!=NULL )
    {
        printf ("%c", vpCn->Value);
        vpCn = vpCn->Previous;
    }
}



int main ()
{
    string vsString1;
    string vsString2;

    funcstringInit (&vsString1);
    funcstringInit (&vsString2);

    funcstringInput (&vsString1);
    printf ("the size of string is: %d\n", vsString1.length);
    funcstringDisplay (vsString1);
    printf ("\n\n");
    funcstringInput (&vsString2);
    printf ("the size of string is: %d\n", vsString2.length);

    funcstringDisplay (vsString2);
    printf ("\n\n");



    // int viCmp;
    // viCmp = funcstringCompare (vsString1, vsString2);
    
    // if ( viCmp==0 )
    // {
    //     printf ("the string are equal.\n");
    // }
    // else if ( viCmp==1 )
    // {
    //     printf ("the string1 is greater then string2");
    // }
    // else
    // {
    //     printf ("the string2 is greater then string1");
    // }
    // print ("\n\n");



    // printf ("after concatenation:\n");
    // funcstringConcate (&vsString1, vsString2);
    // printf ("string1: ");
    // funcstringDisplay (vsString1);
    // printf ("\n");
    // printf ("the size of the string is: %d.\n", vsString1.length);
    // printf ("\n\n");
    // printf ("string2: ");
    // funcstringDisplay (vsString2);
    // printf ("\n");
    // printf ("the size of the string is: %d.\n", vsString2.length);
    // printf ("\n\n");



    // printf ("Copying the string1 in string2:\n");
    // funcstringCopy ( &vsString2, vsString1 );
    // funcstringDisplay ( vsString2 );
    // printf ("\n\n");



    // printf ("is it alphanumeric or not:\n");
    // bool vbAlphaNumeric = funcstringIsAlphaNumeric (vsString1);
    // if ( vbAlphaNumeric )
    // {
    //     printf ("is alphanumeric");
    // }
    // else
    // {
    //     printf ("is not alphanumeric");
    // }

    // printf ("uppering string:\n");
    // funcstringUpper (&vsString1);
    // funcstringDisplay (vsString1);



    return 0;
}