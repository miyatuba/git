using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InputManager : MonoBehaviour
{

    private bool isUpArrowKey = false;
    private bool isDownArrowKey = false;
    private bool isLeftArrowKey = false;
    private bool isRightArrowKey = false;

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

        if (Input.GetKeyDown(KeyCode.LeftArrow)) {
            this.isLeftArrowKey = true;
        }

        if (Input.GetKeyDown(KeyCode.RightArrow)) {
            this.isRightArrowKey = true;
}
    }

    public void LoopReset()
    {
        this.isUpArrowKey = false;
        this.isDownArrowKey = false;
        this.isLeftArrowKey = false;
        this.isRightArrowKey = false;
    }

    public bool IsUpArrowKey()
    {
        return this.isUpArrowKey;
    }

    public bool IsDownArrowKey()
    {
        return this.isDownArrowKey;
    }

    public bool IsLeftArrowKey()
    {
        return this.isLeftArrowKey;
    }

    public bool IsRightArrowKey()
    {
        return this.isRightArrowKey;
    }
}
