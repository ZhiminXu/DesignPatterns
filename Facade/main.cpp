#include "MovieFacade.h"

void main()
{
	MovieFacade* pMovieFacade = new MovieFacade();
	pMovieFacade->OpenMovie();
	pMovieFacade->CloseMovie();
}