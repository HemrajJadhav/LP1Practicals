﻿Imports ClassLibrary1
Public Class Form1
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim Obj As New ClassLibrary1.MyFunctions
        TextBox3.Text = Obj.AddMyValues(CDbl(TextBox1.Text), CDbl(TextBox2.Text)).ToString
    End Sub
End Class
