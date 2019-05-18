# NTU_BioMedical_Experiment: Polygraph

Principle
=============
People's body signals will react differently when they are telling a lie, for example:
  * Skin Resistance decrease
  * Heartbeat increase
  * Short and light of breath
  * High peak on brain alpha and beta wave

Experiment design
=================
We make ten number cards from 1 to 10. We ask our subject pick one number in his/her mind and always say no when we ask the number.
We will orderly guess the number from 1 to 10, assuming that subject's mood is affected more when the guessing approaching his/her number.
By recording and analyzing the subject's biosignal, we are able to tell the number they pick in the begin of the experiment.

Test User Number: 5


Sensors
==============
* Galvanic skin reponse
* ECG circuit
* HeuroSky brainwave starter kit

Software Architecture
=====================
Sensors -> Arduino(MCU) -> Duo(openUART) -> Thingspeak Cloud


More Detial
================
See 生醫實驗第八組期末專題報告.docx
