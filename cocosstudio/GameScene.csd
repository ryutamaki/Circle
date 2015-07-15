<GameProjectFile>
  <PropertyGroup Type="Scene" Name="GameScene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="2.3.0.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Field" ActionTag="-1286772574" Tag="26" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-88.0000" RightMargin="-88.0000" TopMargin="-248.0000" BottomMargin="-248.0000" ctype="SpriteObjectData">
            <Size X="1136.0000" Y="1136.0000" />
            <Children>
              <AbstractNodeData Name="Character" ActionTag="-1204876553" Tag="10" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="374.8800" RightMargin="761.1200" TopMargin="568.0000" BottomMargin="568.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
                <Size />
                <AnchorPoint />
                <Position X="374.8800" Y="568.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3300" Y="0.5000" />
                <PreSize />
                <FileData Type="Normal" Path="Character.csd" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Enemy" ActionTag="-605961977" Tag="10" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="749.7599" RightMargin="386.2401" TopMargin="568.0000" BottomMargin="568.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
                <Size />
                <AnchorPoint />
                <Position X="749.7599" Y="568.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.6600" Y="0.5000" />
                <PreSize />
                <FileData Type="Normal" Path="Enemy.csd" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.1833" Y="1.7750" />
            <FileData Type="Normal" Path="Assets/Images/Field.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="AButton" ActionTag="-1809146847" Tag="17" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="785.9999" RightMargin="114.0001" TopMargin="482.0000" BottomMargin="98.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="30" Scale9Height="38" ctype="ButtonObjectData">
            <Size X="60.0000" Y="60.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="815.9999" Y="128.0000" />
            <Scale ScaleX="2.0000" ScaleY="2.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8500" Y="0.2000" />
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