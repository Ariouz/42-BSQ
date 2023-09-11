# 42-BSQ
Projet BSQ pour la Piscine C de 42

# TODO

- [ ] Parsing Map
  - [ ] Recuperer 3 dernier char de la premiere ligne dans une struct
  - [ ] Recuperer l1 - 3 derniers pour atoi, struct
- [ ] Map valide:
  - [X] Verifier si nb lignes = l1, sinon - map error\n
  - [ ] Si une ligne contient un char qui n'est pas empty, obstacle - map error\n
  - [X] Verifier que toutes les lignes aient la meme taille, sinon - map error\n
  - [ ] Si premiere ligne, char full et empty et obstacle sont identiques - map error\n
  - [ ] Nb de lignes >= 2 (1 ere compte pas) et col >= 1, sinon - map error\n
- [ ] Makefile
- [X] Solveur
- [ ] Gestion d'erreur
- [ ] Verifier TOUS les malloc / free
