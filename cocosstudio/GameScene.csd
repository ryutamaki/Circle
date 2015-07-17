<GameProjectFile>
  <PropertyGroup Type="Scene" Name="GameScene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="2.3.0.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Background" ActionTag="93126980" Tag="53" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" RightMargin="-176.0000" TopMargin="-64.0000" BottomMargin="-64.0000" ctype="SpriteObjectData">
            <Size X="1136.0000" Y="768.0000" />
            <Children>
              <AbstractNodeData Name="Field" ActionTag="88501566" Tag="54" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="88.0000" RightMargin="88.0000" TopMargin="64.0000" BottomMargin="64.0000" ctype="SpriteObjectData">
                <Size X="960.0000" Y="640.0000" />
                <Children>
                  <AbstractNodeData Name="Character" ActionTag="-1204876553" Tag="10" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="316.8000" RightMargin="643.2000" TopMargin="320.0000" BottomMargin="320.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
                    <Size />
                    <AnchorPoint />
                    <Position X="316.8000" Y="320.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.3300" Y="0.5000" />
                    <PreSize />
                    <FileData Type="Normal" Path="Character.csd" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Enemy" ActionTag="-605961977" Tag="10" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="633.6000" RightMargin="326.4000" TopMargin="320.0000" BottomMargin="320.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
                    <Size />
                    <AnchorPoint />
                    <Position X="633.6000" Y="320.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6600" Y="0.5000" />
                    <PreSize />
                    <FileData Type="Normal" Path="Enemy.csd" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="568.0000" Y="384.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.8451" Y="0.8333" />
                <FileData Type="Normal" Path="Assets/Images/Field.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleY="0.5000" />
            <Position Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition Y="0.5000" />
            <PreSize X="1.1833" Y="1.2000" />
            <FileData Type="Normal" Path="Assets/Images/Background.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="AButton" ActionTag="-1809146847" Tag="17" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="834.0000" RightMargin="66.0000" TopMargin="514.0000" BottomMargin="66.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="30" Scale9Height="38" OutlineSize="0" ShadowOffsetX="0" ShadowOffsetY="0" ctype="ButtonObjectData">
            <Size X="60.0000" Y="60.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="864.0000" Y="96.0000" />
            <Scale ScaleX="2.0000" ScaleY="2.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9000" Y="0.1500" />
            <PreSize X="0.0625" Y="0.0938" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Normal" Path="Assets/Images/A.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>