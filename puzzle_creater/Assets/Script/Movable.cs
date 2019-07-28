using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movable : MonoBehaviour
{

    private Vector3 moveTo;

    private bool isClick = false;
    public GameObject delete_object;


    // Use this for initialization
    void Start()
    {
        this.delete_object = GameObject.Find("Delete");
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(1))
        {
            this.RotationObject();
        }

        if (Input.GetMouseButtonDown(0))
        {
            this.RayCheck();
        }

        if (this.isClick)
        {
            if (this.delete_object.GetComponent<Delete>().isDeleteMode())
            {
                this.DeleteThis();
            }
            else
            {
                this.MovePoisition();
            }
        }

        if (Input.GetMouseButtonUp(0))
        {
            this.isClick = false;
        }

    }

    private void RotationObject()
    {
        Ray ray = new Ray();
        RaycastHit hit = new RaycastHit();
        ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        if (Physics.Raycast(ray.origin, ray.direction, out hit, Mathf.Infinity) && hit.collider == gameObject.GetComponent<Collider>())
        {
            this.transform.Rotate(0.0f, 0.0f, 90);
        }
            
    }

    private void RayCheck()
    {
        Ray ray = new Ray();
        RaycastHit hit = new RaycastHit();
        ray = Camera.main.ScreenPointToRay(Input.mousePosition);

        if (Physics.Raycast(ray.origin, ray.direction, out hit, Mathf.Infinity) && hit.collider == this.gameObject.GetComponent<Collider>()) {
            this.isClick = true;
        }
        else {
            this.isClick = false;
        }

    }

    public void MovePoisition()
    {
        //これを生成したオブジェクトに変える
        Vector3 mousePos = Input.mousePosition;
        mousePos.z = 10;

        moveTo = Camera.main.ScreenToWorldPoint(mousePos);
        this.transform.position = moveTo;
        
    }

    public void DeleteThis()
    {
        Destroy(this.gameObject);
    }
}
