## st_envia_email_coord
* cumprimentar
    - utter_cumprimentar
* enviar_email_coordenador
    - utter_pega_corpo_email
*  mandar_corpo_email {"corpo_email_coordenador": "corpo do email"}
    - action_monta_res_coordenador
    - utter_email_enviado

## st_envia_email_prof
* cumprimentar
    - utter_cumprimentar
* enviar_email_professor
    - utter_pega_materia
* mandar_materia
    - utter_pega_corpo_email
* mandar_corpo_email {"corpo_email_professor": "corpo do email"}
    - action_monta_res_professor
    - utter_email_enviado    

## st_pega_media
* cumprimentar
    - utter_cumprimentar
* obter_media
    - utter_pega_materia_media
* mandar_materia
    - action_media_disciplina
    - utter_media_disciplina

## st_data_prova
* cumprimentar
    - utter_cumprimentar
* data_prova
    - action_data_prova
    - utter_data_prova
    

