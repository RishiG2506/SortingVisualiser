all: compile run

compile:
	g++ -Iheaders -Isrc/include -Lsrc/lib -o app source_files/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

run: app.exe
	.\app.exe

clean:
	rm -f app.exe