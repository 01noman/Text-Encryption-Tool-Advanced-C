#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int login();
void signup();
void showmainMenu();
void clearBuffer();
void encryptText();
void decryptText();
void encryptFile();
void decryptFile();
void autoGenerate();
void logHistory();

void clearBuffer()
{
    int c;
    while((c=getchar())!='\n' && c != EOF);
}

int main()
{
    int choice;
    printf("=====================================\n");
    printf("   TEXT ENCRYPTION TOOL (SECURE)\n");
    printf("=====================================\n");
    scanf("%d",choice);

    while (1)
    {
        printf("\n1.Login\n2.Signup\n3.Exit\nEnter your choice: ");
        scanf("%d",&choice);

        if (choice==1)
        {
            if(login())
            {
                showmainMenu();
            }
        }
        else if (choice==2)
        {
            signup();
        }
        else if(choice==3)
        {
            printf("\nExiting program...\n");
            break;
        }
        else
        {
            printf("Invalid Choice\n");
        }    
    }
   return 0; 
}

void showmainMenu()
{
    int choice,key,method;
    char text[200];
    char infile[100];
    char outFile[100];

    do
    {
        printf("\n==============================");
        printf("\n     SECURE ENCRYPTION MENU");
        printf("\n==============================");
        printf("\n1. Encrypt Text");
        printf("\n2. Decrypt Text");
        printf("\n3. Encrypt File");
        printf("\n4. Decrypt File");
        printf("\n5. Logout");
        printf("\n------------------------------");
        printf("\nEnter your choice");
        scanf("%d",&choice);
        clearBuffer();

        switch (choice)
        {
        case 1:
            printf("\nChoose Encryption Method:\n1. ASCII Method\n2. XOR Method\nEnter Method: ");
            scanf("%d",&method);
            printf("Enter key(number): ");
            scanf("%d",&key);
            clearBuffer();
            printf("Enter text to encrypt: ");
            fgets(text,sizeof(text),stdin);
            text[strcspn(text,"\n")]='\0';
            encryptText(text,key,method);
            printf("\nEncyrpted Text: %s\n",text);
            break;
        case 2:
            printf("\nChoopse Decryption Method:\n1. ASCII Method\n2. XOR Method\nEnter Method: ");
            scanf("%d",&method);
            printf("Enter key(number): ");
            scanf("%d",&key);
            clearBuffer();
            printf("Enter Text to Decrypt: ");
            fgets(text,sizeof(text),stdin);
            text[strcspn(text,"\n")]='\0';
            decryptText(text,key,method);
            printf("\nDecrypted Text: %s\n",text);
            break;
        case 3:
            printf("\nChoose Encryption method:\n1. ASCII Method\n2. XOR Method\nEnter Method: ");
            scanf("%d",&method);
            printf("Enter key(0=Auto-Generate): ");
            scanf("%d",&key);
            if(key==0)
            {
                autoGenerate();
            }
            printf("Enter InputFile name: ");
            scanf("%s",&infile);
            printf("Enter OutputFile Name: ");
            scanf("%s",&outFile);
            encryptFile(infile,outFile,key,method);
            break;
        case 4:
            printf("\nChoose Encryption method:\n1. ASCII Method\n2. XOR Method\nEnter Method: ");
            scanf("%d",&method);
            printf("Enter key: ");
            scanf("%d",&key);
            printf("Enter InputFile Name: ");
            scanf("%s",&infile);
            printf("Enter OutputFile Name: ");
            scanf("%s",&outFile);
            decryptFile(infile,outFile,key,method);
            break;
        case 5:
            FILE *fp = fopen("history.txt","r");
            if(!fp)
            {
                printf("No Records Found\n");
                break;
            }
            char line[260];
            printf("\n========== HISTORY ==========\n");
            while(fgets(line,sizeof(line),fp))
            {
                printf("%s",line);
            }
            fclose(fp);
            printf("\n=============================\n");
            break;
        default:
            break;
        }
    } while (1);
    
}

void encryptText(char text[], int key, int method)
{
    for(int i=0; text[i]!='\0'; i++)
    {
        if(method==1)
        {
            text[i]=text[i]+key;
        }
        else if(method==2)
        {
            text[i]=text[i]^key;
        }
    }
}

void decryptText(char text[], int key, int method)
{
    for(int i=0; text[i]!='\0'; i++)
    {
        if(method==1)
        {
            text[i]=text[i]-key;
        }
        else if(method==2)
        {
            text[i]^key;
        }
    }
}   

void encryptFile(const char *infile, const char *outfile, int key, int method)
{
    FILE *fin = fopen(infile,"r");
    FILE *fout = pfopen(outfile,"w");
    if(!fin || !fout)
    {
        printf("Error Opening File\n");
        return;
    }
    
    char ch;
    while(ch=getc(fin) !=EOF);
    {
        if(method ==1)
        {
            fputc(ch+key,fout);
        }
        else if(method==2)
        {
            fputc(ch^key,fout);
        }
    }
    fclose(fin);
    fclose(fout);

    printf("\nFile Encrypted Successfully %s\n",outfile);
    logHistory("Encrypted",key,method,outfile);
}

void decrypetedFile(const char *infile,const char *outfile, int key, int method)
{
    FILE *fin = fopen(infile,"r");
    FILE *fout= fopen(outfile,"w");

    if(!fin || !fout)
    {
        printf("No Record Founds\n");
        return;
    }

    char ch;
    while(ch=getch(infile)!=EOF)
    {
        if(method==1)
        {
            fputc(ch-key,fout);
        }
        else if(method==2)
        {
            fputc(ch^key,fout);
        }
    }
    fclose(fin);
    fclose(fout);

    printf("\nFile Decrypted Successfully %s\n",outfile);
    logHistory("Decrypted",key,method,outfile);
}
