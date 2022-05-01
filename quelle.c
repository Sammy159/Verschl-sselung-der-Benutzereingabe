#include <stdio.h>
#include <math.h>	
#include <limits.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
							//Deklaration der Funktionen
void ZyklischeErsetzung();
void Verschiebung();
void Kombi();
int Eingabe(char* text);
int Schluesselanf();
int SchluesselEingabeVerschiebung(char* SchluesselVerschiebung);
int Befehlseingabe(char* befehlsfolge);
int EnDeCrypt();
void ZyklischeErsetzungEncrypt(int SchluesselErsetzung, char* text);
void ZyklischeErsetzungDecrypt(int SchluesselErsetzung, char* text);
void VerschiebungEncrypt(char* SchluesselVerschiebung, char* Verschluesselung, char* text);
void VerschiebungDecrypt(char* SchluesselVerschiebung, char* Verschluesselung, char* text);
void Sortieren(char* SchluesselVerschiebung, int* SortierArray);
void temp_VerschiebungEncrypt(char* SchluesselVerschiebung, char* temp_Verschluesselung, char* text);


void main(void)
{
	int run = 1;																					/*Variable für eine Loop, welche auf Status 1 bzw. High gesetzt wird*/
	do																								/*Do-Schleife welche für Loop des Programmes sorgt, nach erfoglreicher Berechnung wird das Auswahlmenue wieder ausgegeben*/
	{
		double ausw;
		int Eingabetest;

		printf("\n***************AUSWAHLMENUE**************\n");						            	/*Hier wird das Auswahlmenü in der Konsole ausgegeben*/
		printf("*                                       *\n");
		printf("*        1.) Zyklische Ersetzung        *\n");
		printf("*        2.) Verschiebung               *\n");
		printf("*        3.) Kombi                      *\n");
		printf("*        4.) Abbruch                    *\n");
		printf("*                                       *\n");
		printf("*****************************************\n");
		printf("AUSWAHL: ");
		int rueckAuswahl = scanf("%lf", &ausw);												    	/*Hier wird die Eingabe eingelesen*/
		printf("\n");
		Eingabetest = ausw;
		if ((rueckAuswahl != 1) || (ausw < 1 || ausw > 4) || ((ausw - Eingabetest) != 0))
		{
			printf("Falsche Eingabe.\n\n");												        	/*Fehlermeldung*/
			while (getchar() != '\n');
		}
		else if (ausw == 1)
		{
			ZyklischeErsetzung();
			run = 1; continue;
		}
		else if (ausw == 2)
		{
			Verschiebung();
			run = 1; continue;																/* Neustart des Programmes/Loop*/
		}
		else if (ausw == 3)
		{
			Kombi();
			run = 1; continue;																/* Neustart des Programmes/Loop*/
		}
		else if (ausw == 4)																				/*Abbruch*/
		{
			printf("Abbruch\n\n");
			run = 0;
		}
	} while (run);
}

void ZyklischeErsetzung()
{
	char* text = malloc(sizeof(char) * 100);		//Fehlerprüfung
	if (text == NULL)
	{
		return;
	}
	int EingabeFehler = Eingabe(text);
	if (EingabeFehler == 0)
	{
		free(text);
		return;
	}
	else
	{
		int SchluesselErsetzung = Schluesselanf();
		int EnDeCryptAusw = EnDeCrypt();
		if (SchluesselErsetzung == '#');				//Bei fehlerhafter Eingabe diesen Block überspringen;
		else
		{
			if (EnDeCryptAusw == 1)			//Verschlüsselung
			{
				ZyklischeErsetzungEncrypt(SchluesselErsetzung, text);
				printf("Der verschluesselte Text heisst: %s", text);
				printf("\n");
			}
			else if (EnDeCryptAusw == 2)	//Entschlüsselung
			{
				ZyklischeErsetzungDecrypt(SchluesselErsetzung, text);
				printf("Der entschluesselte Text heisst: %s", text);
				printf("\n");
			}
			else
			{
				printf("Falsche Eingabe.\n\n");
			}
		}
	}
	free(text);
}

void Verschiebung()
{
	char* text = malloc(sizeof(char) * 100);		//Fehlerprüfung
	if (text == NULL)
	{
		return;
	}
	int EingabeFehler = Eingabe(text);
	if (EingabeFehler == 0)
	{
		free(text);
		return;
	}
	else
	{
		char* SchluesselVerschiebung = malloc(sizeof(char) * 100);
		if (SchluesselVerschiebung == NULL)								//Fehlerprüfung
		{
			return;
		}
		int EingabeFehlerSchluessel = SchluesselEingabeVerschiebung(SchluesselVerschiebung);
		if (EingabeFehlerSchluessel == 0)								//Fehlerprüfung
		{
			free(text);
			return;
		}
		else
		{
			char* Verschluesselung = malloc(sizeof(char) * 100);
			int EnDeCryptAusw = EnDeCrypt();
			if (EnDeCryptAusw == 1)				//Verschlüsselung
			{
				printf("\nVerschluesseltes Wort: ");
				VerschiebungEncrypt(SchluesselVerschiebung, Verschluesselung, text);
				for (int i = 0; i <= strlen(Verschluesselung); i++) printf("%c", Verschluesselung[i]);
				printf("\n");
			}
			else if (EnDeCryptAusw == 2)			//Entschlüsselung
			{
				printf("\nEntschluesseltes Wort: ");
				VerschiebungDecrypt(SchluesselVerschiebung, Verschluesselung, text);
				for (int i = 0; i <= strlen(Verschluesselung); i++) printf("%c", Verschluesselung[i]);
				printf("\n");
			}
			else
			{
				printf("Falsche Eingabe.\n\n");
			}
		}
		free(SchluesselVerschiebung);
	}
	free(text);
}

void Kombi()
{
	char* text = malloc(sizeof(char) * 100);
	if (text == NULL)
	{
		return;
	}
	int EingabeFehler = Eingabe(text);
	if (EingabeFehler == 0)
	{
		free(text);
		return;
	}
	else
	{
		printf("\n\n");
		printf("************************Kombinationsverfahren************************\n");						            	/*Hier wird das Auswahlmenü in der Konsole ausgegeben*/
		printf("*                                                                   *\n");
		printf("*        z  <Zahl>: Verschluesseln durch Zyklische Ersetzung        *\n");
		printf("*        zi <Zahl>: Entschluesseln durch Zyklische Ersetzung        *\n");
		printf("*        v  <Schluessel>: Verschluesseln durch Verschiebung         *\n");
		printf("*        vi <Schluessel>: Entschluesseln durch Verschiebung         *\n");
		printf("*                                                                   *\n");
		printf("*********************************************************************\n");

		char* befehlsfolge = malloc(sizeof(char) * 100);
		if (text == NULL)					//Fehlerprüfung
		{
			return;
		}
		int EingabeFehlerBefehlsfolge = Befehlseingabe(befehlsfolge);
		if (EingabeFehlerBefehlsfolge == 0)			//Fehlerprüfung
		{
			free(text);
			return;
		}
		else       //Kombinationsalgorithmus
		{
			int befehlsfolgePos = 0;
			int SchluesselKombi[100] = { 0 };
			int SchluesselErsetzung = 0;
			char SchluesselVerschiebung[100] = { 0 };
			int befehlsfolgeLaenge = strlen(befehlsfolge);
			befehlsfolge[befehlsfolgeLaenge - 1] = ' ';
			char Verschluesselung[100];
			while (befehlsfolgePos <= befehlsfolgeLaenge)
			{
				if (befehlsfolge[befehlsfolgePos] == 'z')
				{
					int SchluesselErsetzung = 0;					//Soll bei jedem Schleifendurchlauf auf 0 zurückgesetzt werden	
					befehlsfolgePos++;
					if (befehlsfolge[befehlsfolgePos] == 'i')		//Fall zi
					{
						befehlsfolgePos++;		//i überspringen
						befehlsfolgePos++;		//Leerzeichen überspringen
						auto int SchluessellaengeKombi = 0;
						while (befehlsfolge[befehlsfolgePos + SchluessellaengeKombi] != ' ')	//Einlesen der Verschiebungszahl in Array
						{
							SchluesselKombi[SchluessellaengeKombi] = befehlsfolge[befehlsfolgePos + SchluessellaengeKombi];			//Schlüssel als Integerwert abspeichern (ist aber char 66 =/= 6+6)
							SchluessellaengeKombi++;
						}
											// Char Schlüssel in Integer Schlüssel umwandeln
						auto double j = 0.;
						for (int i = SchluessellaengeKombi - 1; i >= 0; i--)
						{
							int hochzahl = pow(10, j);
							SchluesselErsetzung += (SchluesselKombi[i] - 48) * hochzahl;		//1er Stelle * 1; 10er Stelle * 10 ... //[2]1 [1]10 [0]100 -> 111
							j++;
						}
								//Funktion Zyklische Ersetzung
						ZyklischeErsetzungDecrypt(SchluesselErsetzung, text);
					}

					else //Fall z
					{
						befehlsfolgePos++;		//Leerzeichen überspringen

						auto int SchluessellaengeKombi = 0;
						while (befehlsfolge[befehlsfolgePos + SchluessellaengeKombi] != ' ')		//Einlesen der Verschiebungszahl in Array
						{
							SchluesselKombi[SchluessellaengeKombi] = befehlsfolge[befehlsfolgePos + SchluessellaengeKombi];				//Schlüssel als Integerwert abspeichern (ist aber char 66 =/= 6+6)
							SchluessellaengeKombi++;
						}
						// Char Schlüssel in Integer Schlüssel umwandeln
						auto double j = 0.;
						for (int i = SchluessellaengeKombi - 1; i >= 0; i--)
						{
							int hochzahl = pow(10, j);
							SchluesselErsetzung += (SchluesselKombi[i] - 48) * hochzahl;		//1er Stelle * 1; 10er Stelle * 10 ... //[2]1 [1]10 [0]100 -> 111
							j++;
						}
								//Funktion Zyklische Ersetzung
						ZyklischeErsetzungEncrypt(SchluesselErsetzung, text);
					}
					befehlsfolgePos++;
					befehlsfolgePos++;
				}

				else if (befehlsfolge[befehlsfolgePos] == 'v')
				{
					if (befehlsfolge[befehlsfolgePos + 1] == 'i')	//Fall vi - entschlüsseln
					{
						befehlsfolgePos++;		//v überspringen
						befehlsfolgePos++;		//i überspringen
						befehlsfolgePos++;		//Leerzeichen überspringen
						char SchluesselVerschiebung[20] = { 0 };
						auto int zaehler = 0;
						while (befehlsfolge[befehlsfolgePos] != ' ')	//Einlesen des Verschiebungsschlüssel in Array
						{
							SchluesselVerschiebung[zaehler] = befehlsfolge[befehlsfolgePos];
							befehlsfolgePos++;
							zaehler++;
						}
										//Entschlüsselungsalgorithmus
						VerschiebungDecrypt(SchluesselVerschiebung, Verschluesselung, text);
						auto int VerschluesselungLaenge = strlen(Verschluesselung);
						auto int counter = 0;
						while (counter != VerschluesselungLaenge)		//Entschlüsselten Text ins array text zurückgeben, sodass bei weiteren Befehlen dieser text hergenommen wird
						{
							text[counter] = Verschluesselung[counter];
							counter++;

						}
						text[counter] = '\0';
						befehlsfolgePos++;
					}
					else  //Fall v - verschlüsseln
					{
						befehlsfolgePos++;		//v überspringen
						befehlsfolgePos++;		//Leerzeichen überspringen

						char SchluesselVerschiebung[20] = { 0 };
						auto int zaehler = 0;
						while (befehlsfolge[befehlsfolgePos] != ' ')	//Einlesen des Verschiebungsschlüssel in Array
						{
							SchluesselVerschiebung[zaehler] = befehlsfolge[befehlsfolgePos];
							befehlsfolgePos++;
							zaehler++;
						}
										//Verschlüsselungsalgorithmus
						VerschiebungEncrypt(SchluesselVerschiebung, Verschluesselung, text);

						auto int VerschluesselungLaenge = strlen(Verschluesselung);
						auto int counter = 0;
						while (counter != VerschluesselungLaenge)			//Verschlüsselten Text ins array text zurückgeben, sodass bei weiteren Befehlen dieser text hergenommen wird
						{
							text[counter] = Verschluesselung[counter];
							counter++;
						}
						text[counter] = '\0';
						befehlsfolgePos++;
					}
				}
				else            //Falls kein weitere Befehls vorhanden ist, Ausgabe
				{
					printf("\nVerschluesseltes Wort:");
					for (int i = 0; i <= strlen(text); i++) printf("%c", text[i]);
					printf("\n");
					return;
				}
			}
		}


	}
}

int Eingabe(char* text)
{
	int zeichen=0;
	int laenge = 0;
	printf("Gebe einen Text ein (hoechstens 99 Zeichen und beende mit #): ");
	do
	{
		zeichen = _getch();			
		if ((zeichen >= 0) && (zeichen != '#'))					//Eingabebedingungen, so dass nur das eingegeben werden kann, was auch verschlüsselt werden kann, # soll Eingabe beenden
		{
			if ((zeichen >= 'A') && (zeichen <= 'Z'))			//Wenn A-Z Gross eingetippt wird mache diese zu a-z klein
			{
				printf("%c", zeichen + 32);
				text[laenge] = zeichen + 32;
			}
			else if (zeichen == 13)								//Wenn Enter gedrückt, mache dies zu " " (Space Taste)
			{
				printf(" ");
				text[laenge] = 32;
			}
			else if (zeichen == 8)								//Wenn Backspace gedrückt, lösche vorherige eingabe
			{
				if (laenge > 0)
				{
					text[laenge] = "\n";
					laenge--;
					text[laenge] = "\n";
					laenge--;
					printf("\b");
					printf(" ");
					printf("\b");
				}
				else {}
			}
			else												// Alle andere Zeichen werden so wie sie sind abgebildet
			{
				printf("%c", zeichen);
				text[laenge] = zeichen;
			}
			laenge++;
		}
	} while ((zeichen >= 0) && (zeichen != '#') && (laenge < 99));
	text[laenge] = '\0';									//Nullterminierung nach texteingabe
	if (laenge >= 99)									//Fehlerprüfung
	{
		printf("\nZu langer Text. Hoechtens 99 Zeichen erlaubt.\n");
		text[1] = '\0';
		return 0;
	}
	return 1;
}

int Schluesselanf()
{
	int SchluesselErsetzung;
	char fehler = '#';
	printf("\n");
	printf("Bitte geben Sie den Schluessel ein (nur Ziffern): ");	//Anforderung des Ersetzungsschlüssel
	int rueck = scanf("%d", &SchluesselErsetzung);
	if (rueck != 1) { printf("Fehlerhafte Eingabe."); while (getchar() != '\n');  return fehler; }	//Fehlerprüfung
	return(SchluesselErsetzung);
}

int SchluesselEingabeVerschiebung(char* SchluesselVerschiebung)
{
	int zeichen=0;
	int laenge = 0;
	printf("\n");
	printf("Gebe einen Schluessel ein (hoechstens 9 Zeichen): ");	
	do
	{
		zeichen = _getch();					
		if ((zeichen >= 0) && (zeichen != 13))						//Eingabebedingungen, so dass nur das eingegeben werden kann, was auch verschlüsselt werden kann
		{
			if ((zeichen >= 'A') && (zeichen <= 'Z'))				//Wenn A-Z Gross eingetippt wird mache diese zu a-z klein
			{
				printf("%c", zeichen + 32);
				SchluesselVerschiebung[laenge] = zeichen + 32;
			}
			else if (zeichen == 32)									// Ignoriere Leertaste
			{
				if (laenge > 0)
				{
					laenge--;
				}
			}
			else if (zeichen == 8)					//Wenn Backspace gedrückt, lösche vorherige eingabe
			{
				if (laenge > 0)
				{
					SchluesselVerschiebung[laenge] = "\n";
					laenge--;
					SchluesselVerschiebung[laenge] = "\n";
					laenge--;
					printf("\b");
					printf(" ");
					printf("\b");
				}
				else {}
			}
			else
			{
				printf("%c", zeichen);
				SchluesselVerschiebung[laenge] = zeichen;
			}
			laenge++;
		}
	} while ((zeichen >= 0) && (zeichen != 13) && (laenge < 9));
	printf("\n");
	SchluesselVerschiebung[laenge] = '\0';
	if (laenge >= 9)													//Fehlerüberprüfung
	{
		printf("\nZu langer Text. Hoechstens 9 Zeichen erlaubt.\n");	
		SchluesselVerschiebung[1] = '\0';
		return 0;
	}
	return 1;
}

int Befehlseingabe(char* befehlsfolge)
{
	int zeichen=0;
	int laenge = 0;
	printf("Gebe die Befehlsfolge ein (hoechstens 99 Zeichen und beende mit #): ");
	do
	{
		zeichen = _getch();
		if ((zeichen >= 0) && (zeichen != '#'))						//Großbuchstaben werden zu Kleinbuchstaben
		{
			//int NaechstesChar = laenge++;
			if ((zeichen >= 'A') && (zeichen <= 'Z'))				//Mache aus Großbustaben Kleinbuchstaben
			{
				printf("%c", zeichen + 32);
				befehlsfolge[laenge] = zeichen + 32;
			}
			else if (zeichen == 13)									//Ersetzen von Enter
			{
				printf(" ");
				befehlsfolge[laenge] = 32;
			}
			else if (zeichen == 8)									//Löschen möglich
			{
				if (laenge > 0)
				{
					befehlsfolge[laenge] = "\n";
					laenge--;
					befehlsfolge[laenge] = "\n";
					laenge--;
					printf("\b");
					printf(" ");
					printf("\b");
				}
				else {}
			}
			/*
			else if (befehlsfolge[laenge] == 'z' && befehlsfolge[NaechstesChar] != ' ')
			{
				printf("\nFalsche Eingabe, nach 'z' muss entweder ein 'i' oder ein Leerzeichen folgen\n");
				break;
			}
			else if (befehlsfolge[laenge] == 'z' && befehlsfolge[NaechstesChar] == 'i')
				{
					NaechstesChar = laenge++;
					if (befehlsfolge[NaechstesChar] != ' ')
						{
							printf("\nFalsche Eingabe, nach 'zi' muss ein Leerzeichen folgen\n");
							break;
						}
				}
			else if (befehlsfolge[laenge] == 'v' && befehlsfolge[NaechstesChar] != ' ')
			{
				printf("\nFalsche Eingabe, nach 'v' muss entweder ein 'i' oder ein Leerzeichen folgen\n");
				break;
			}
			else if (befehlsfolge[laenge] == 'v' && befehlsfolge[NaechstesChar] == 'i')
				{
					NaechstesChar = laenge++;
					if (befehlsfolge[NaechstesChar] != ' ')
						{
							printf("\nFalsche Eingabe, nach 'vi' muss ein Leerzeichen folgen\n");
							break;
						}
				}*/
			else
			{
				printf("%c", zeichen);
				befehlsfolge[laenge] = zeichen;
			}
			laenge++;
		}
	} while ((zeichen >= 0) && (zeichen != '#') && (laenge < 99));
	befehlsfolge[laenge + 1] = '\0';
	if (laenge >= 99)								//Fehlerprüfung
	{
		printf("\nZu langer Text. Hoechstens 99 Zeichen erlaubt.\n");
		befehlsfolge[1] = '\0';
		return 0;
	}
	return 1;
}

int EnDeCrypt()
{
	//Auswahl Ver- oder Entschlüsselung
	int ausw;
	char fehler = '#';
	printf("\n***************AUSWAHLMENUE**************\n");
	printf("*                                       *\n");
	printf("*        1.) Verschluesselung           *\n");
	printf("*        2.) Entschluesselung           *\n");
	printf("*                                       *\n");
	printf("*****************************************\n");
	printf("AUSWAHL: ");
	int rueck = scanf("%d", &ausw);
	if (rueck != 1) { printf("Fehlerhafte Eingabe.\n"); while (getchar() != '\n'); return fehler; }	//Fehlerprüfung
	if (ausw == 1)
	{
		return 1;		//Verschlüsselung
	}
	if (ausw == 2)
	{
		return 2;		//Entschlüsselung
	}
	else
	{
		return ausw;
	}
}

void ZyklischeErsetzungEncrypt(int SchluesselErsetzung, char* text)
{
	int laenge = strlen(text);
	for (int i = 0; i < laenge; i++)
	{	
		//Ziffern verändern
		if (text[i] >= 48 && text[i] <= 57)
		{
			SchluesselErsetzung = SchluesselErsetzung % 10;
			if (text[i] + SchluesselErsetzung > 57)
			{
				text[i] = text[i] + SchluesselErsetzung - 10;
			}
			else if (text[i] + SchluesselErsetzung < 48)
			{
				text[i] = text[i] + SchluesselErsetzung + 10;
			}
			else
			{
				text[i] = text[i] + SchluesselErsetzung;
			}
		}
		//Buchstaben verändern
		else if (text[i] >= 97 && text[i] <= 122)
		{
			SchluesselErsetzung = SchluesselErsetzung % 25;
			if (text[i] + SchluesselErsetzung > 122)
			{
				text[i] = text[i] + SchluesselErsetzung - 26;
			}
			else if (text[i] + SchluesselErsetzung < 97)
			{
				text[i] = text[i] + SchluesselErsetzung + 26;
			}
			else
			{
				text[i] = text[i] + SchluesselErsetzung;
			}
		}
		//Leertaste nicht verändern
		else
		{
			text[i] = text[i];
		}
	}
}

void ZyklischeErsetzungDecrypt(int SchluesselErsetzung, char* text)
{
	int laenge = strlen(text);
	for (int i = 0; i < laenge; i++)
	{
		//Ziffern verändern
		if (text[i] >= 48 && text[i] <= 57)
		{
			SchluesselErsetzung = SchluesselErsetzung % 10;
			if (text[i] - SchluesselErsetzung > 57)
			{
				text[i] = text[i] - SchluesselErsetzung - 10;
			}
			else if (text[i] - SchluesselErsetzung < 48)
			{
				text[i] = text[i] - SchluesselErsetzung + 10;
			}
			else
			{
				text[i] = text[i] - SchluesselErsetzung;
			}
		}
		//Buchstaben verändern
		else if (text[i] >= 97 && text[i] <= 122)
		{
			SchluesselErsetzung = SchluesselErsetzung % 25;
			if (text[i] - SchluesselErsetzung > 122)
			{
				text[i] = text[i] - SchluesselErsetzung - 26;
			}
			else if (text[i] - SchluesselErsetzung < 97)
			{
				text[i] = text[i] - SchluesselErsetzung + 26;
			}
			else
			{
				text[i] = text[i] - SchluesselErsetzung;
			}
		}
		//Leertaste nicht verändern
		else
		{
			text[i] = text[i];
		}
	}
}

void VerschiebungEncrypt(char* SchluesselVerschiebung, char* Verschluesselung, char* text)
{
	int Schluessellaenge = strlen(SchluesselVerschiebung);
	int Textlaenge = strlen(text);
	for (int i = Textlaenge; i < (Textlaenge + Schluessellaenge); i++)		//sont leere Stellen mit # auffühlen, damit dies später beachtet werden kann
	{
		text[i] = '#';
	}
	char Matrix[10][20];
	int Zeilen = 0;
	int SortierArray[10];
	int zaehler = 0;

	Sortieren(SchluesselVerschiebung, SortierArray);			//Nach Alphabetstellung sortieren
	Zeilen = Textlaenge / Schluessellaenge;
	if ((Textlaenge % Schluessellaenge) != 0)					//Wenn die Textlänge kein ganzzahliger Teiler des Schlüssels ist, braucht man eine zusätzliche Zeile
	{
		Zeilen++;
	}
			//Matrix erzeugen
	for (int i = 0; i < Zeilen; i++)
	{
		for (int j = 0; j < Schluessellaenge; j++)
		{
			Matrix[SortierArray[j]][i] = text[j + Schluessellaenge * i];

		}
	}
		// Matrix in Array zurückschreiben
	int counter = 0;
	for (int i = 0; i < Schluessellaenge; i++)
	{
		for (int j = 0; j < Zeilen; j++)
		{
			if (Matrix[i][j] != '#') 
			{ 
				Verschluesselung[counter] = Matrix[i][j];
				counter++;
			}
		}
	}
	Verschluesselung[counter] = '\0';
}

void temp_VerschiebungEncrypt(char* SchluesselVerschiebung, char* temp_Verschluesselung, char* text)
{
	int Schluessellaenge = strlen(SchluesselVerschiebung);
	int Textlaenge = strlen(text);
	for (int i = Textlaenge; i < (Textlaenge + Schluessellaenge); i++)			//sont leere Stellen mit # auffühlen, damit dies später beachtet werden kann
	{
		text[i] = '#';
	}
	char Matrix[10][20];
	int Zeilen = 0;
	int SortierArray[10];
	int zaehler = 0;

	Sortieren(SchluesselVerschiebung, SortierArray);			//Nach Alphabetstellung sortieren
	Zeilen = Textlaenge / Schluessellaenge;
	if ((Textlaenge % Schluessellaenge) != 0)					//Wenn die Textlänge kein ganzzahliger Teiler des Schlüssels ist, braucht man eine zusätzliche Zeile
	{
		Zeilen++;
	}
			//Matrix erzeugen
	for (int i = 0; i < Zeilen; i++)
	{
		for (int j = 0; j < Schluessellaenge; j++)
		{
			Matrix[SortierArray[j]][i] = text[j + Schluessellaenge * i];

		}
	}
			// Matrix in Array zurückschreiben
	int counter = 0;
	for (int i = 0; i < Schluessellaenge; i++)
	{
		for (int j = 0; j < Zeilen; j++)
		{
			temp_Verschluesselung[counter] = Matrix[i][j];
			counter++;
		}
	}
	int counterplus = counter + 1;
	temp_Verschluesselung[counter] = '\0';
}


void VerschiebungDecrypt(char* SchluesselVerschiebung, char* Verschluesselung, char* text)
{
	char temp_text[100];
	char temp_Verschluesselung[100];
	int Schluessellaenge = strlen(SchluesselVerschiebung);
	int Textlaenge = strlen(text);
	int Eingabelaenge = strlen(text);

	//erstell temp_text mit genausovielen * char's wie das Wort hat
	for (int i = 0; i < Textlaenge; i++)
	{
		temp_text[i] = "*";
	}
		// Verschlüsseltes Wort mit # 
	temp_VerschiebungEncrypt(SchluesselVerschiebung, temp_Verschluesselung, text);
		//Positionen der # ermitteln
	int temp_Zaehler = 0;
	int text_zu_tempText_Zaehler = 0;
	int temp_Laenge = strlen(temp_Verschluesselung);
	for (int i = 0; i < temp_Laenge; i++)
	{
		if (temp_Verschluesselung[i] == '#')
		{
			temp_text[i] = ' ';
		}
		else
		{
			temp_text[i] = text[temp_Zaehler];
			temp_Zaehler++;
		}
		text_zu_tempText_Zaehler++;
	}
		//temp text --> text
	for (int i = 0; i < temp_Laenge; i++)
	{
		text[i] = temp_text[i];
	}

	for (int i = temp_Laenge; i < (temp_Laenge + Schluessellaenge); i++)
	{
		text[i] = '\0';
	}
	Textlaenge = strlen(text);
	char Matrix[10][20];
	int Zeilen = 0;
	int SortierArray[10];
	Sortieren(SchluesselVerschiebung, SortierArray);			//Nach Alphabetstellung sortieren
	Zeilen = Textlaenge / Schluessellaenge;
	if ((Textlaenge % Schluessellaenge) != 0)					//Wenn die Textlänge kein ganzzahliger Teiler des Schlüssels ist, braucht man eine zusätzliche Zeile
	{
		Zeilen++;
	}
	char sorttext[100];
	int sorttextZaehler = 0;
	for (int i = 0; i < Schluessellaenge; i++)
	{
		for (int j = 0; j < Zeilen; j++)
		{
			sorttext[sorttextZaehler] = text[Zeilen * (SortierArray[i] + 1) - (Zeilen - j)];		//2*1-(2-0) = 0 -> d			//2*5 - (2-0) =8 -> i			//2*6 - (2-0) = 10 ->e			
			sorttextZaehler++;																		//2*1-(2-1) = 1 -> e			//2*5 - (2-1) =9 -> i			//2*6 - (2-1) = 11 ->n
		}
	}
		// sortierten Text Nullterminierung anfügen
	for (int i = Textlaenge; i < (Textlaenge + Schluessellaenge); i++)
	{
		sorttext[i] = '\0';
	}
		// Matrix einlesen
	int Zaehler = 0;
	for (int i = 0; i < Schluessellaenge; i++)
	{
		for (int j = 0; j < Zeilen; j++)
		{
			Matrix[j][i] = sorttext[Zaehler];
			Zaehler++;
		}
	}
		//Matrix in Array zurückschreiben
	int counter = 0;
	for (int j = 0; j < Zeilen; j++)
	{
		for (int i = 0; i < Schluessellaenge; i++)
		{
			Verschluesselung[counter] = Matrix[j][i];
			counter++;
		}
	}
	Verschluesselung[Eingabelaenge] = '\0';
	printf("\n");
}


void Sortieren(char* SchluesselVerschiebung, int* SortierArray)			//Ordnet dem ersten Buchstaben in der Alphabetordnung eine 0 zu, dem Zweiten eine 1, usw. um später nach dieser Folge die Matrix zu ordnen
{
	int AnzahlElemente = strlen(SchluesselVerschiebung);
	int Groesse = 0;
	int i = 0;

	for (i; i < AnzahlElemente; i++) // Vergleicht ArrayPosition i
	{
		for (int j = 0; j < AnzahlElemente; j++)
		{
			if (SchluesselVerschiebung[i] > SchluesselVerschiebung[j])
			{
				Groesse++;
			}
		}
		SortierArray[i] = Groesse;
		Groesse = 0;
	}

}
