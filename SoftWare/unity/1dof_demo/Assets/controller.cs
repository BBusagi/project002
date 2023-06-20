using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using UnityEngine.SceneManagement;

public class controller : MonoBehaviour
{
    public int moveSpeed = 10;
    public int rotateSpeed = 10;
    private float vertical;
    private float horizontal;
    private float timer;
    private float realSpeed;
    public int speedLevel;

    public bool isCrash = false;
    public bool isReversal = false;
    public bool isVertical = false;

    public string portNumber = null;

    public AudioSource sound;

    private SerialPort serialPort; // 串口对象
    public string message;
    public string message_V;
    public string message_H;

    // Start is called before the first frame update
    void Start()
    {
        serialPort = new SerialPort(portNumber, 115200);
        serialPort.Open();
        if (serialPort.IsOpen) { print("Open"); }
    }

    // Update is called once per frame
    void Update()
    {
        StartCoroutine(CalculateSpeed());
        vertical = Input.GetAxis("Vertical"); // 获取垂直方向输入（上下箭头键）
        horizontal = Input.GetAxis("Horizontal"); // 获取水平方向输入（左右箭头键）
        message_V = vertical.ToString("F2");
        message_H = horizontal.ToString("F2");//保留两位数
        Vector3 movement = new Vector3(0.0f, 0.0f, vertical * moveSpeed * 0.01f); //删除Time.deltaTime
        Vector3 rotation = new Vector3(0.0f, horizontal * rotateSpeed * 0.1f, 0.0f);   //删除Time.deltaTime
        transform.Translate(movement);
        transform.Rotate(rotation);

        //if (Input.GetKeyDown(KeyCode.Z))
        //{
        //    sound.Play();
        //}
        //if (Input.GetKeyDown(KeyCode.X))
        //{
        //    sound.Stop();
        //}


    }
    IEnumerator CalculateSpeed()
    {
        Vector2 lastPosition = new Vector2(this.transform.position.x, this.transform.position.z) * 10;
        yield return new WaitForFixedUpdate();
        realSpeed = (lastPosition - new Vector2(this.transform.position.x, this.transform.position.z) * 10).magnitude / Time.deltaTime;
        realSpeed = realSpeed / 10;
        //Debug.Log(realSpeed);

        if (realSpeed < 0.01) realSpeed = 0;

        if ((int)realSpeed == 0) { speedLevel = 0; }
        else if ((int)realSpeed < 3) { speedLevel = 1; }
        else { speedLevel = 2; }
        //speedLevel = (int)realSpeed;
        //Debug.Log(realSpeed+ "    Sp   " + speedLevel);
    }


    private void FixedUpdate()
    {
        timer += Time.fixedDeltaTime;
        if (timer >= 0.2) //0.5秒一次执行
        {
            SendMessage();
            timer = 0;
        }
    }

    void OnCollisionEnter(Collision collision)
    {
        if (collision.collider.tag == "Sign")
        {
            isCrash = true;
            Debug.Log("Crash");
            //sound.Play(); //是否打开碰撞用媒体音
        }
    }
    void OnCollisionExit(Collision collision)
    {
        isCrash = false;
        sound.Stop();
    }


    private void SendMessage()
    {
        if (vertical != 0 || horizontal != 0)
        {
            if (vertical > 0)
            {
                if (isReversal) { message = "2"; }
                else if (isVertical) { message = "3"; }
                else { message = "1"; }
            }
            else if (vertical < 0)
            {
                if (isReversal) { message = "1"; }
                else if (isVertical) { message = "4"; }
                else { message = "2"; }
            }
            else if (horizontal < 0)
            {
                if (isVertical) 
                { 
                    message = "1";
                    speedLevel = 2;
                }
                else
                {
                    message = "4";
                }
            }
            else if (horizontal > 0)
            {
                if (isVertical) 
                { 
                    message = "2";
                    speedLevel = 2;
                }
                else
                {
                    message = "3";
                }
            }

            //Debug.Log("mes:" +message+";speed:"+speedLevel);
            message = message + ";" + speedLevel;
            Debug.Log(message);
            serialPort.WriteLine(message);
            serialPort.BaseStream.Flush();
        }
    }

    public void toolVerticalBool()
    {
        isVertical = !isVertical;
    }
    public void toolReversalBool()
    {
        isReversal = !isReversal;
    }

}
