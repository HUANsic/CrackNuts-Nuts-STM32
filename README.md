# NutsLib Reference Manual

# Chapter 1 概览

## 介绍

`NutsLib`模块旨在为`Nuts`（被测芯片）与 `Cracker`（测试设备）提供简单易用的通信功能，
支持 UART、SPI、I2C 等多种通信协议，
并为使用不同芯片的 `Nuts` 提供一个标准的软件接口，
方便用户专注于核心功能开发。

项目开源地址：https://github.com/HUANsic/Cracknuts-Nuts-STM32

## 特性

- 提供统一命令
  - Nut_Init(void)
  - Nut_Loop(void)
  - Nut_Quiet(void)
  - Nut_Unquiet(void)
  - Nut_LED(bool);
  - Nut_Trigger_Set(void)
  - Nut_Trigger_Clear(void)
  - Nut_IO_1(bool)
  - Nut_IO_2(bool)
  - Nut_IO_3(bool)
  - Nut_IO_USER()

- 支持硬件列表
  - STM32F103C8TX
  - STM32F407VGTX
  - STM32F439VGTX
  - STM32L476RGTX
  - STM32L486RGTX
  - 以及其它STM32系列单片机


# Chapter 2 功能描述

![](.figure/nutslib-structure-stm32.png)

用户在STM32配置文件（.ioc）中分配引脚及外设后，需要在`NutsLib_Config.h`中进行定义。


# Chapter 3 使用方法

## 项目导入过程

以 STM32F103C8T6 为例

### 克隆GitHub仓库

```git clone git@github.com:HUANsic/Cracknuts-Nuts-STM32.git```

或者

```git clone https://github.com/HUANsic/Cracknuts-Nuts-STM32.git```


### STM32CubeIDE导入工程

`菜单栏`-`文件`-`从文件系统中打开项目`：

![](.figure/file-open.png)

选择`目录`：

![](.figure/open-page.png)

选择整个文件夹：

![](.figure/select-folder.png)

点击完成：

![](.figure/open-project.png)

这时应该看到一个文件夹出现在IDE中，其中包含一系列不同芯片的工程：

![](.figure/opened-project.png)


### 编译工程

点击选中想要编译的项目后，点击编译按钮（锤子）：

![](.figure/compile-1.png)

即可开始编译。


### 下载工程

点击选中想要下载的项目后，点击下载按钮：

![](.figure/download-1.png)

即可开始编译，编译完成后自动开始下载。


## 新建项目过程

### 新建源文件夹（可选）

`菜单栏`-`文件`-`新建`-`源文件夹`：

![](.figure/new_project-new-projFolder.png)

选择`通用`-`项目`，这将创建一个可以包含其它工程和文件的文件夹：

![](.figure/new_project-projFolder-1.png)

选择文件夹位置并输入文件夹名，点击完成：

![](.figure/new_project-projFolder-2.png)


### 创建项目

在工程目录或菜单栏创建新的STM32工程：

![](.figure/new_stm32project-1.png)

选择芯片型号：

![](.figure/new_stm32project-SelectChip.png)

选择工程位置（建议在源文件夹内新建同名空文件夹）：

![](.figure/new_stm32project-SelectLocation.png)

进行引脚配置：

![](.figure/new_stm32project-PinConfig.png)

使用`NutsLib`时，要求**至少定义1个GPIO用作Trigger信号输出和一个全双工UART用作通讯**，
还可以额外定义2个GPIO用作输出和1个GPIO用作输入，
以及1个SPI从机、1个I2C从机（开发中）、一个CAN设备（开发中）。

以上引脚与外设定义需要额外在[NutsLib_Config.h](#editconfig)中定义。


### 导入`NutsLib`文件夹（独立STM32工程）

从文件系统中直接将`NutsLib`文件夹拖到**STM32工程**的`Core`文件夹中：

![](.figure/ImportLibrary-CopyFolder.png)

并选择复制文件与文件夹，使其与`Inc`、`Src`、`Startup`同级：

![](.figure/ImportLibrary-CopyFolder-1.png)


### 导入`NutsLib`文件夹（同一源文件夹内存在多个STM32工程）

从文件系统中将`NutsLib`文件夹拖到**源文件夹**中：

![](.figure/ImportLibrary-CopyFolder.png)

并选择**复制文件与文件夹**，使其与工程文件夹`Example_F103RC`同级：

![](.figure/ImportLibrary-LinkFolder-1.png)

拖动源文件夹中的`NutsLib`文件夹，按住`Ctrl`将其复制到每一个STM32工程的`Core`文件夹中：

![](.figure/ImportLibrary-LinkFolder-2.png)

并选择**链接文件与文件夹**，使其与`Inc`、`Src`、`Startup`同级：

![](.figure/ImportLibrary-LinkFolder-3.png)


### 添加头文件包含路径

要想让编译器找到`NutsLib`，需要将其加到`IncludePath`中。

选中STM32工程，右键进入`属性`页，进入`C/C++通用`-`路径与符号`的`Includes`标签页：

![](.figure/AddIncludePath-1.png)

点击`添加`，选择`工作区`：

![](.figure/AddIncludePath-2.png)

无论是独立的STM32工程还是同一源文件夹中的多个STM32工程，选择**工程内的`NutsLib`文件夹**：

![](.figure/AddIncludePath-3.png)

点击确认：

![](.figure/AddIncludePath-4.png)

应用并关闭页面：

![](.figure/AddIncludePath-5.png)


### 编辑`NutsLib`配置文件 {#EditConfig}

在每个STM32工程的`Inc`文件夹内新建头文件`NutsLib_Config.h`，
或者将本仓库的`NutsLib_Config.h`复制到`Inc`中：

![](.figure/Config-AddFile.png)

在`NutsLib_Config.h`中，需要定义以下内容：

- `NUT_BUFFER_SIZE`：
接收缓冲区和发送缓冲区的大小，实际占用`NUT_BUFFER_SIZE`\*2的RAM空间。
通常情况下设置为512是够用的。

- `NUT_LED_PORT`和`NUT_LED_PIN`：
板载LED引脚的定义。

- `NUT_IO_USER_PORT`和`NUT_IO_USER_PIN`：
用户输入信号。可以是板载按键或者来自`Cracker`的输入信号等。

- `NUT_IO1_PORT`和`NUT_IO1_PIN`：
Trigger输出引脚的定义。

- `NUT_IO2_PORT`和`NUT_IO2_PIN`：
GP\_02输出引脚的定义。

- `NUT_IO3_PORT`和`NUT_IO3_PIN`：
GP\_03输出引脚的定义。

- `NUT_UART`：
用于和`Cracker`通讯的UART外设。

- `NUT_SPI`、`NUT_SPI_CS_PORT`和`NUT_SPI_CS_PIN`：
用于和`Cracker`通讯的SPI外设及片选输入引脚。

- `NUT_I2C`：
用于和`Cracker`通讯的I2C外设。（开发中）

- `NUT_CAN`：
用于和`Cracker`通讯的CAN外设。（开发中）


### 编辑`main.c`

在每个STM32工程中找到`main.c`，
在第24行左右找到`USER CODE BEGIN Includes`注释，
并包含`NutsLib`库：

```
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "NutsLib.h"
/* USER CODE END Includes */
```

在`main`函数中找到`USER CODE BEGIN 2`注释，
并进行初始化：

```
	/* USER CODE BEGIN 2 */
	Nut_Init();
	/* USER CODE END 2 */
```

找到`USER CODE BEGIN WHILE`注释，并循环调用`Nut_Loop`：

```
	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		Nut_Loop();
	/* USER CODE END WHILE */

	/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
```

至此，项目配置已经完成，可以编译工程。


## 项目结构

### 文件结构

本项目源文件夹内存在多个STM32工程：
`NUT_F103C8TX`、`NUT_F407VGTX`、`NUT_F439VGTX`、`NUT_L476RGTX`、`NUT_L486RGTX`。
它们的`NutsLib`链接到同一个磁盘中的文件夹，共享同一套`user`代码。

项目中文件结构如下：

```
CrackNuts-Nuts-STM32
├── NUT_F103C8TX
    ├── Core
        ├── Inc
        ├── NutsLib
        ├── Src
        └── Startup
    ├── NUT_F103C8TX.ioc
    └── ...
├── NUT_F407VGTX
    ├── Core
        ├── Inc
        ├── NutsLib
        ├── Src
        └── Startup
    ├── NUT_F407VGTX.ioc
    └── ...
├── NUT_F439VGTX
    ├── Core
        ├── Inc
        ├── NutsLib
        ├── Src
        └── Startup
    ├── NUT_F439VGTX.ioc
    └── ...
├── NUT_L476RGTX
    ├── Core
        ├── Inc
        ├── NutsLib
        ├── Src
        └── Startup
    ├── NUT_L476RGTX.ioc
    └── ...
├── NUT_L486RGTX
    ├── Core
        ├── Inc
        ├── NutsLib
        ├── Src
        └── Startup
    ├── NUT_L486RGTX.ioc
    └── ...
├── NutsLib
    ├── NutsLib.c
    ├── NutsLib.h
    ├── user.c
    └── user.h
└── README.md
```


系统中文件结构如下：

```
CrackNuts-Nuts-STM32
├── .figure
├── NUT_F103C8TX
    ├── Core
        ├── Inc
        ├── Src
        └── Startup
    ├── NUT_F103C8TX.ioc
    └── ...
├── NUT_F407VGTX
    ├── Core
        ├── Inc
        ├── Src
        └── Startup
    ├── NUT_F407VGTX.ioc
    └── ...
├── NUT_F439VGTX
    ├── Core
        ├── Inc
        ├── Src
        └── Startup
    ├── NUT_F439VGTX.ioc
    └── ...
├── NUT_L476RGTX
    ├── Core
        ├── Inc
        ├── Src
        └── Startup
    ├── NUT_L476RGTX.ioc
    └── ...
├── NUT_L486RGTX
    ├── Core
        ├── Inc
        ├── Src
        └── Startup
    ├── NUT_L486RGTX.ioc
    └── ...
├── NutsLib
    ├── NutsLib.c
    ├── NutsLib.h
    ├── user.c
    └── user.h
├── README.md
└── ...
```

注意到所有的工程在文件系统中并没有`NutsLib`文件夹，
因此在任何一个STM32工程中修改`user.c`中的代码，
都会在其它项目中出现相同的修改。

这项工程旨在统一不同项目的通信协议指令格式，
如果需要添加单个项目特有的功能，
请在`NutsLib_Config.h`中添加宏定义，
然后在`user.c`中对宏定义进行判断。


### 代码结构

- NutsLib_Config.h：对每个项目使用的引脚与外设进行定义。

- NutsLib.h/.c：负责处理与`Cracker`的通信，并提供统一的接口调用函数。

- user.h/.c：用户定义的功能代码，包括所有指令定义及其实现函数。


## 通信协议

通信内容包括指令（Command）或状态（Status），以及载荷（Payload）。

主机（`Cracker`）发送的格式为指令+载荷（CMD+PLD），从机（Nut）发送的格式为状态+载荷（STA+PLD）。

从机接收的逻辑如下：

![](.figure/nutslib-decode-flow-stm32.png)


## mbedtls介绍







# Chapter 4 设计流程



1. 定义命令
2. 明确收发数据长度
3. 增加功能函数
4. 返回数据及状态







# Chapter 5 示例



## 用户功能示例

以echo功能为例，Trigger



## GPIO控制示例

微信里用户提出的问题





# Chapter6 进阶功能



- STM32配置时钟



- 改变时钟频率，采集曲线，细节展示



- 改为外部时钟，采集曲线，细节展示



- STM32配置Cache功能示例



# 附录



## 不同Nut的管脚配置

个性：不同Nut对应的管脚配置







