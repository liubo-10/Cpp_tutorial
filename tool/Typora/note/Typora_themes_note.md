# Typora

* 👋 Hi, I’m bliu2-10
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...









## 字体

字体添加方法

```css
@font-face {
  font-family: 'yang';
  font-style: normal;
  font-weight: normal;
  src: local("yang"), url("./my_front/杨任东竹石体-Medium.ttf") format("truetype");
}

```





Monaco-1

consola-1

这两个字体似乎不能用









```css
#write {
  font-size: 20px;   /*控制文本字体大小*/
  max-width: 860px; 
  margin: 0 auto;
  padding: 30px;
  padding-bottom: 100px;
  font-family: monospace,'yang';
}

h1,
h2,
h3,
h4,
h5,
h6 {
  position: relative;
  margin-top: 1rem;
  margin-bottom: 1rem;
  font-weight: bold;
  line-height: 1.4;
  cursor: text;

  font-family: 'Consolas', 'yang';/*标题字体，Consolas似乎不起作用*/
}




.CodeMirror-wrap .CodeMirror-code pre {
  font-family:  monospace;/*代码字体*/

}



```







## 边距

```css

@media only screen and (min-width: 1400px) {
  #write {
    max-width: 1024px;
  }
}

@media only screen and (min-width: 1800px) {
  #write {
    max-width: 1600px;/*设置界面边距，第二个起作用*/
  }
}



```





## 代码



代码格式与颜色

```css
.CodeMirror-line .cm-number{color:#7f6bff} /*数字，蓝色*/
.CodeMirror-line .cm-property {color: #f08d49;}
.CodeMirror-line .cm-variable-3{color:#ffed6b} /*返回值、变量类型，int、void等，淡黄色*/
.CodeMirror-line .cm-qualifier{color:#888}
.CodeMirror-line .cm-variable-2 {color: #888;} 
.CodeMirror-line .cm-meta{ color:#BBFFFF}  /* 头文件、宏定义一整行 青色*/
.CodeMirror-line .cm-atom { color:#f9ff00} /* true、false 黄色*/
.CodeMirror-line .cm-keyword{    color: #ff1800;} /* if、return等关键字红色*/
.CodeMirror-line .cm-def{ color:#00ff00  } /* 函数定义，绿色 */
.CodeMirror-line .cm-variable { color: #90EE90; } /* 入参定义，亮绿色 */
.CodeMirror-line .cm-builtin {color: #82AAFF;}/* 蓝色 */
.CodeMirror-line .cm-comment {color: #888;} /* 灰色 */
.CodeMirror-line .cm-string{ color: #82AAFF  } /* 字符串， 蓝色*/
.CodeMirror-line .cm-string-2 { color: #888  }
.CodeMirror-line .cm-operator {color: #ff1800}/* +=等操作符，红色*/
.CodeMirror div.CodeMirror-cursor {border-left: 1px solid #fff; z-index: 3;}
.CodeMirror-selected,
.CodeMirror-selectedtext {background: #666 !important;}
.CodeMirror-line .cm-tag{color: #F07178;}
.CodeMirror-line .cm-bracket{color: #FFF;}
.CodeMirror-line .cm-attribute{color: #FFCB6B;}
.CodeMirror-wrap .CodeMirror-code pre {font-family:monospace;}

```

















---
---
---
---
---
---
---
---
---
---
---
---
---
