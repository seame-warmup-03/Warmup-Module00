EXE		=	./phonebook

SRC		=	./main.cpp \
			./Utils.cpp \
			./Phone.cpp \
			./Content.cpp \
			./Contacts.cpp \
			./Contacts.add.cpp \
			./Contacts.search.cpp \
			./Contacts.remove.cpp \
			./Contacts.bookmark.cpp

GCC		=	g++

FLG		=	-std=c++11

all:
	$(GCC) $(FLG) -o $(EXE) $(SRC)

clean:
	rm -rf $(EXE)

re:
	$(clean)
	$(all)

run:
	$(EXE)