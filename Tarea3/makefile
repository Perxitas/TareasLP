SRC_DIR := Tarea3
BIN_DIR := bin
JAVAC := javac
JAVA := java

MAIN_CLASS := Juego
INTERFAZ_CLASSES := $(wildcard $(SRC_DIR)/Interfaz/*.java)
PIKINIM_CLASSES := $(wildcard $(SRC_DIR)/Pikinim/*.java)
ZONAS_CLASSES := $(wildcard $(SRC_DIR)/Zonas/*.java)

INTERFAZ_BIN := $(BIN_DIR)/Interfaz
PIKINIM_BIN := $(BIN_DIR)/Pikinim
ZONAS_BIN := $(BIN_DIR)/Zonas

all: $(MAIN_CLASS)

$(MAIN_CLASS): $(MAIN_CLASS).class
$(MAIN_CLASS).class: $(SRC_DIR)/$(MAIN_CLASS).java $(INTERFAZ_CLASSES) $(PIKINIM_CLASSES) $(ZONAS_CLASSES)
	$(JAVAC) -d $(BIN_DIR) $^

$(INTERFAZ_BIN)/%.class: $(SRC_DIR)/Interfaz/%.java
	$(JAVAC) -d $(INTERFAZ_BIN) $<

$(PIKINIM_BIN)/%.class: $(SRC_DIR)/Pikinim/%.java
	$(JAVAC) -d $(PIKINIM_BIN) $<

$(ZONAS_BIN)/%.class: $(SRC_DIR)/Zonas/%.java
	$(JAVAC) -d $(ZONAS_BIN) $<

run: all
	$(JAVA) -cp $(BIN_DIR) $(MAIN_CLASS)

clean:
	rm -rf $(BIN_DIR)/*
