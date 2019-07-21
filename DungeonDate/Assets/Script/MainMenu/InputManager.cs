using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InputManager : MonoBehaviour
{

    private bool isUpArrowKey = false;
    private bool isDownArrowKey = false;

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
         
    }

    public void InputCheck()
    {
        if (Input.GetKeyDown(KeyCode.UpArrow)) {
            this.isUpArrowKey = true;
        }

        if (Input.GetKeyDown(KeyCode.DownArrow)) {
            this.isDownArrowKey = true;
        }
    }

    public void LoopReset()
    {
        this.isUpArrowKey = false;
        this.isDownArrowKey = false;
    }

    public bool IsUpArrowKey()
    {
        return this.isUpArrowKey;
    }

    public bool IsDownArrowKey()
    {
        return this.isDownArrowKey;
    }

}
