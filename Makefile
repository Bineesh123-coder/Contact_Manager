CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = contact_manager
SRC = main.cpp contact_manager.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)