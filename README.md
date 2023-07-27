# Softskills Gruppe 4
Smarter wetterbasierter Fensterkontakt

Inbetriebsnahme

1. Laden Sie den folgenden Code von GitHub herunter:
(https://github.com/marcohenning-uol/softskills-group4/blob/main/main.ino)

2. Binden Sie die folgenden Bibliotheken in Arduino ein: Arduino Json, WifiManager und ESP8266HTTPClient

3. Erstellen Sie sich einen Account bei OpenWeatherMap (OpenWeatherMap) und ersetzten Sie den Platzhalter der Variable “API_KEY” mit ihrem API Key. Geben Sie bei der Variable “CITY” ihre Stadt ein.

4. Erstellen Sie einen Account bei IFTTT (IFTTT).
Klicken Sie “Create” -> “If This” -> Wählen Sie “Webhooks” aus -> Wählen Sie “Receive A Web Request” aus -> Nennen Sie das Event “send_email” -> Klicken Sie “Create Trigger”.
Klicken Sie als nächtes auf “Then That” -> Wählen sie “Email” und dann “Send me an Email” aus -> Passen Sie den Betreff und Email Inhalt nach ihren Wünschen an -> Klicken Sie “Create Action”, dann “Continue” und dann “Finish”.
Nehmen Sie als nächtes ihren persönlichen API Key und geben diesen bei der Variable “IFTTT_API_KEY” ein.

5. Laden Sie den Code auf den Microcontroller

6. Verstauen Sie den Microcontroller und seinen Akku im Gehäuse und befästigen Sie ihn am Fenster und Fensterrahmen.

7. Verbinden Sie sich, falls Sie den smarten wetterbasierten Fensterkontakt zum ersten Mal nutzen, mit ihrem WLan.


Known Issues & Limitations

-Unsicherheit der Wetterdaten: Da der Fensterkontakt auf die Wetterdaten Ihres Standorts angewiesen ist, kann keine hundertprozentige Garantie dafür gegeben werden, dass es tatsächlich regnet, wenn eine Benachrichtigung gesendet wird. Wettervorhersagen können manchmal ungenau sein, weshalb die Möglichkeit von Fehlalarmen besteht

-Abhängigkeit von Internetverbindung: Unser Fensterkontakt benötigt eine aktive Internetverbindung, um die aktuellen Wetterdaten abzurufen. Wenn die Internetverbindung instabil ist oder ausfällt, kann das dazu führen, dass keine Nachricht gesendet wird.
