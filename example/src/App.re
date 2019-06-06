open ReasonWindow;

[@react.component]
let make = () => {
    <FixedSizeList
        className={"prueba"}
        direction={FixedSizeList.Ltr}
        height={200}
        itemCount={1000}
        itemSize={50}
        layout={FixedSizeList.Vertical}
        onItemsRendered={Js.log}
        onScroll={Js.log}
        useIsScrolling={true}
        style={ReactDOMRe.Style.make(~background="red", ())}
        overscanCount={10}
        width={200}
    >
        {cellProps => <Cell cellProps/>}
    </FixedSizeList>
};