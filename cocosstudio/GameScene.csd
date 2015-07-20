<GameProjectFile>
  <PropertyGroup Type="Scene" Name="GameScene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="2.3.0.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Background" ActionTag="93126980" Tag="53" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" RightMargin="-176.0000" TopMargin="-63.5000" BottomMargin="-63.5000" ctype="SpriteObjectData">
            <Size X="1136.0000" Y="767.0000" />
            <Children>
              <AbstractNodeData Name="Field" ActionTag="-1430883737" Tag="86" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="88.0000" RightMargin="88.0000" TopMargin="63.5000" BottomMargin="63.5000" ctype="SpriteObjectData">
                <Size X="960.0000" Y="640.0000" />
                <Children>
                  <AbstractNodeData Name="Character" ActionTag="-1204876553" Tag="10" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="192.0000" RightMargin="768.0000" TopMargin="320.0000" BottomMargin="320.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
                    <Size />
                    <AnchorPoint />
                    <Position X="192.0000" Y="320.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.2000" Y="0.5000" />
                    <PreSize />
                    <FileData Type="Normal" Path="Character.csd" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Enemy" ActionTag="-605961977" Tag="10" Rotation="180.0000" RotationSkewX="180.0000" RotationSkewY="180.0000" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="768.0000" RightMargin="192.0000" TopMargin="320.0000" BottomMargin="320.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
                    <Size />
                    <AnchorPoint />
                    <Position X="768.0000" Y="320.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.8000" Y="0.5000" />
                    <PreSize />
                    <FileData Type="Normal" Path="Enemy.csd" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="568.0000" Y="383.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.8451" Y="0.8344" />
                <FileData Type="Normal" Path="Assets/Images/Resources-2x/Field@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleY="0.5000" />
            <Position Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition Y="0.5000" />
            <PreSize X="1.1833" Y="1.2000" />
            <FileData Type="Normal" Path="Assets/Images/Resources-1x/Background.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>