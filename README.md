# 🌌 Sistema de Rotação de Planetas em OpenGL / Planet Rotation System in OpenGL

Este projeto é uma **atividade prática** desenvolvida para a disciplina de **Computação Gráfica** do curso de **Ciência da Computação**.  
This project is a **practical assignment** developed for the **Computer Graphics** course in the **Computer Science** program.

O objetivo é criar uma **simulação simplificada do sistema solar**, mostrando a rotação de planetas e luas em torno de um sol utilizando a biblioteca **OpenGL** com **GLUT**.  
The goal is to create a **simplified solar system simulation**, showing the rotation of planets and moons around the sun using **OpenGL** with **GLUT**.

## 🚀 Funcionalidades / Features

- Desenho do **Sol**, **dois planetas** e **duas luas** utilizando `glutWireSphere`.  
  Draw the **Sun**, **two planets**, and **two moons** using `glutWireSphere`.
- Implementação de **transformações geométricas**: rotação e translação para simular órbitas.  
  Implementation of **geometric transformations**: rotation and translation to simulate orbits.
- Controle interativo via teclado:  
  Interactive keyboard controls:
  - `d` / `D`: girar os corpos celestes sobre o próprio eixo (dia)  
    Rotate celestial bodies on their own axis (day)
  - `y` / `Y`: simular a rotação em torno do sol (ano)  
    Simulate rotation around the sun (year)
  - `q`: sair do programa / quit the program
- Dois modos de visualização possíveis (comentado):  
  Two possible view modes (commented in code):
  - **Visão frontal / Frontal view** (ativa / active)
  - **Visão de cima / Top view** (comentada / commented)

## 🛠 Tecnologias / Technologies

- Linguagem / Language: **C**
- Biblioteca gráfica / Graphics library: **OpenGL / GLUT**

## 📚 Aprendizados / Learning Outcomes

- Aplicação de **matrizes de transformação** para simulação de órbitas.  
  Applying **transformation matrices** to simulate orbits.
- Uso de **pilha de matrizes** (`glPushMatrix` e `glPopMatrix`) para hierarquia de movimentos.  
  Using **matrix stack** (`glPushMatrix` and `glPopMatrix`) for movement hierarchy.
- Manipulação de **teclado** e **viewport** para interação e visualização.  
  Handling **keyboard** and **viewport** for interaction and visualization.

## 🧑‍💻 Autor / Author

Felipe Gabriel Marques dos Santos  
Disciplina: Computação Gráfica / Course: Computer Graphics  
Curso: Ciência da Computação / Program: Computer Science
