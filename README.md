# Objectif
Implémentation d'un chenillard sur la carte DE-10 Lite en utilisant Quartus et un système NIOS II.

# I. Introduction :
L'objectif de ce rapport est de présenter le travail réalisé au cours des travaux pratiques de l'UE Conception Conjointe, axés sur l'approfondissement et la mise en pratique des connaissances à travers la création d'une architecture NIOS. Cette dernière a été utilisée pour coder un chenillard en langage C. Le cahier des charges était simple, consistant à utiliser la plate-forme DE-10 équipée d'un FPGA Max-10 pour développer un chenillard.

# II. Architecture :
À partir de ce cahier des charges, nous avons défini l'architecture à mettre en place sur la plate-forme designer.

inserer image

Après la génération du fichier VHDL et la compilation du design, j'ai attribué les pins de mon design aux E/S de la DE-10 via le Pin Planner de Quartus. Le JTAG UART est également utilisé pour le débogage de l'application à travers la console NIOS II.

# III. Design du code C :
Nous entrons maintenant dans la partie centrale du TP.
Le clignotement des LEDs se réalise à travers un while itérant sur le nombre de LEDs, avec un décalage de 1 bit vers la gauche en fonction de la valeur envoyée sur le bus de sortie connecté aux LEDs. Pour assurer la continuité du processus. La variable "time" gère la vitesse, et à chaque appui sur le bouton, une interruption est générée. Cette fonction lit la valeur du bus switch et ajuste le délai entre chaque décalage de bit en fonction de cette valeur, avec l'état zéro où toutes les LEDs sont allumées. Les détails complets du code sont disponibles dans le dossier "software/app".

iserer image

# IV. Conclusion :
Ce TP a été une introduction fructueuse à l'utilisation d'interruptions, à la conception d'une architecture basée sur NIOS, et à l'implémentation d'un code C sur cette architecture. Vous pouvez visionner une démonstration de mon système dans la vidéo associée.

insérer vidéo
