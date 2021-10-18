using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OpenDoor : MonoBehaviour
{
    public bool firstDoor = false;
    public bool finalDoor = false;

    public ArduinoInputs arduino;

    public GameObject door1;
    public GameObject door2;

    // Update is called once per frame
    void Update()
    {
        // Arduino inputs
        if(arduino.GetHIDInput() == 2)  // When the first puzzle button is pressed
        {
            // Open First Door
            firstDoor = true;
            door1.SetActive(false);
        }
        if(arduino.GetHIDInput() == 4)  // When the second puzzle button is pressed
        {
            finalDoor = true;
            door2.SetActive(false);
        }

        // Wizard of Oz
        if (OVRInput.GetDown(OVRInput.Button.One, OVRInput.Controller.RTouch))
        {
            // Open First Door
            firstDoor = true;
            door1.SetActive(false);
        }
        if (firstDoor)
        {
            if (OVRInput.GetDown(OVRInput.Button.Two, OVRInput.Controller.RTouch))
            {
                // Open Final Door
                finalDoor = true;
                door2.SetActive(false);
            }
        }
    }
}
